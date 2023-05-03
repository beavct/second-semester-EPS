section .bss 
num_entrada: resd 1
input: resd 1
num_prox_p: resd 1
flag_primo: resb 1
mult1: resd 1
mult2: resd 1
flag_encontramos_mult: resb 1
buffer: resd 1

section .data
digito: db '1'
tamanho_impresso: equ $ - digito
tam: db 1,'1'
tam_espaco: db 1, '1'
espaco: db 1, ' '
quebra: db 1, '',0x0A
MAX: db 9
modo: db 1

global _start  
 
section .text
_start: 

      CALL le_input                 ; lemos o primeiro input que é o modo de execução do programa
      MOV dword[buffer], 0
      
      CMP byte[modo], 1
      JE modo_1                     ; comparamos o valor da variável modo, caso seja = 1 então queremos calcular os multiplicadores, então pulamos para o rótulo modo_1

      modo_0:
      CALL prox_primo
      MOV eax, dword[num_prox_p]
      CALL imprimir
      CALL imprimir_quebra
      CALL fim

      modo_1:
      MOV eax, dword[num_entrada]
      CALL mult_primos
      CMP byte[flag_encontramos_mult], 1
      JNE modo_1_fim                ; se a flag não for igual a 1, significa que o número não é múltiplo de primos
      MOV eax, dword[mult1]
      CALL imprimir
      CALL imprimir_espaco 
      MOV eax, dword[mult2]
      CALL imprimir
      CALL imprimir_quebra

      modo_1_fim:
      CALL fim

imprimir_quebra:
      MOV rax, 1                    ; chamada de sistema sys_write
      MOV rdi, 1                    ; stdout
      MOV rsi, quebra               ; endereço da mensagem
      MOV rdx, tam                  ; tamanho da string de mensagem
      SYSCALL                       ; chamada ao sistema operacional
      RET

imprimir_espaco: ; o problema de imprimir o buffer (acho que em rsi) esta nessa funcao e na imprimir_espaco
      MOV rax, 1                    ; chamada de sistema sys_write
      MOV rdi, 1                    ; stdout
      MOV rsi, espaco               ; endereço da mensagem
      MOV rdx, tam_espaco           ; tamanho da string de mensagem
      SYSCALL  
      RET  

le_input:
      MOV rax, 0                    ; chamada de sistema sys_read
      MOV rdi, 0 
      MOV rsi, buffer               ; endereço da váriavel onde será armazenada a string lida
      MOV rdx, 16
      SYSCALL

      MOV rcx, buffer               ; movemos o número do buffer para o contador para podermos olhar seu tamanho
      MOV dword[input], 0           ; inicializamos 

      pegar_modo: 
      MOV bl, byte[rcx]             ; movemos o primeiro byte guardado em rcx para bl
      SUB bl, '0'                   ; então subtraímos 0 para que o valor guardado em bl seja em ASCII
      MOV byte[modo], bl            ; e como o primeiro byte da string se referia ao modo de execução, o movemos para a [modo]
      INC rcx                       ; pulamos o endereço de memória do primeiro dígito, que é o modo
      INC rcx                       ; pulamos o endereço de memória do segundo dígito, que é o espaço

      continua5: 
      CMP byte[rcx], '0'            ; compara a quantidade de bytes do número que está em rcx com o número 0
      JL fim_leitura                ; se for menor do que 0 significa que já convertemos todos os números 

      MOV rax, 10                   ; iniciamos rax com para nos prepararmos para uma multiplicação 
      MUL dword[input]              ; vamos aumentando as casas decimais a cada volta que vamos no laço, reconstruindo o número da string no laço 
      MOV [input], rax

      MOV bl, byte[rcx]             ; byte por byte olhamos o número do buffer que agora está em rcx 
      SUB bl, '0'                   ; transformamos a string em inteiro atravez da subtração com 0 que em ASCII é 0x48
      ADD [input], rbx              ; finalmente adicionamos o número convertido em inteiro em nossa variável 

      INC rcx ; 
      JMP continua5

      fim_leitura:
      MOV eax, dword[input]
      MOV dword[num_entrada], eax
      RET

eh_primo:
      PUSH  rax                     ; inicializa rsp (topo da pilha, que seria o n no código em C), que será usado na divisão, com o valor guardado no 
      MOV ebx, 2                    ; iniciazliza ebx(%rbx) como 2, seria como o i no código em C   

      c_eh_primo: 
      CMP rbx, qword[rsp]           ; compara o contador i e o rsp para saber se dever sair do loop ou não
      JGE ok_primo                  ; se for maior ou igual ao rsp sai do loop, o número é primo, pois não saiu do loop antes do i ser maior/igual o próprio número
      JL loop1                      ; se o contador for menor que o rsp continua no loop

      loop1: 
      XOR  edx, edx                 ; para um possível resto de divisão anterior não atrapalhar
      DIV ebx                       ; divide o conteúdo de eax por ebx, o resto vai para rdx
      CMP rdx, 0                    ; verifica se o resto é 0, em caso positivo o número não é primo
      JZ n_primo                    ; se o resto for igual a 0 sai do loop, pois o número não é primo
      INC ebx                       ; incrementa o ebx(i)
      MOV rax, qword[rsp]           ; iguala novamente o registrador eax ao topo da pilha (número), pois no processo de divisão o quociente foi guardado lá
      JMP c_eh_primo                ; volta para onde o i vai ser comparado e iremos verifificar se vamos sair do loop ou não

      ok_primo: 
      MOV byte[flag_primo], 1       ; flag_primo é usado como uma "flag" para saber se o número é primo ou não, nesse caso flag=1=TRUE
      JMP fim_eh_p                  ; vai para o fim da função
                  
      n_primo: 
      MOV byte[flag_primo], 0       ; flag=0=FALSE

      fim_eh_p: 
      POP rax                       ; desempilha o topo da pilha para poder dar o ret
                                    ; zera os registradores usados na função pra não dar problema 
      XOR ebx, ebx
      XOR edx, edx
      RET 

prox_primo:
      loop2: 
      INC rax                       ; assim como o código em C, incrementa o número
      CALL eh_primo                 ; chama a função eh_primo, que vai pegar o valor em rax, colocar na pilha, etc...
      CMP byte[flag_primo], 0       ; compara o registrador flag_primo que irá ser usado só pela função eh_primo como uma flag 
      JZ loop2                      ; se for igual a 0 então o número não é primo e devemos voltar para o loop
      MOV dword[num_prox_p], eax    ; move para a váriavel o valor do próximo número primo que nos foi retornado no registrador rax, será útil na hora de imprimir o número

      fim_prox_p: 
                                    ; zera os registradores usados na função pra não dar problema
      MOV byte[flag_primo], 0
      RET

mult_primos:
      PUSH rax                      ; coloca o número na pilha, pois posteriormente iremos usar o registrador eax para a multiplicação
      MOV byte[flag_encontramos_mult], 0 ; iniciamos a flag com o valor 0 que representara o falso      
      MOV ebx, 2                    ; preparação para a divisão
      DIV ebx                       ; iniciamos o rax como número/2 assim como o código em C, será como o nosso i
      MOV dword[mult1], eax         ; move o valor de rdx para o multiplicador 1 TALVEZ SEJA EDX

      comp_mult_p:
      CMP dword[mult1], 2           ; enquanto o valor do multiplicador 1 for maior do que 2, continuamos dentro do laço (que seria nosso while no codigo em C)
      JGE loop3                     ; se o multiplicador 1 ainda for maior que 2 continua no laço
      JMP fim_mult_p
      
      loop3:
      MOV rax, qword[rsp]           ; preparação para a divisãoAAA
      MOV rdx, 0                    ; para que não atrapalhe na próxima divisão
      DIV dword[mult1]              ; seria equivalente a encontrar o valor de j no codigo em C
      MOV dword[mult2], eax         ; colocamos o resultado da divisão anterior, o j, no multiplicador 2
      MOV eax, dword[mult1]         ; nos preparamos para chamar a subrotina eh_primo e realizar uma comparação
      CALL eh_primo           
      CMP byte[flag_primo], 1       
      JE continua1                  ; se o primeiro multiplicador for primo, continuamos para as próximas comparações
      JNE decrementa                ; seguimos para o novo valor do multiplicador 1
      continua1: 
      MOV eax, dword[mult2]    
      CALL eh_primo                 ; mesma coisa do anterior
      CMP byte[flag_primo], 1       ; 
      JE continua2                  ;
      JNE decrementa                ;
      continua2: 
      MOV eax, dword[mult1]         ; preparação para a divisão, é esperado que um dos multiplicadores espeja em edx
      MUL dword[mult2]              ;
      CMP rax, qword[rsp]           ; o resultado da divisão foi para rax, logo realizamos a ultima comparação do while
      JE eh_igual                   ; se for igual queremos deixar marcado que encontramos os dois multiplicadores, se nao ocorrer esse jump ja vamos decrementar o número logo em baixo
      
      decrementa:
      DEC dword[mult1]              ; decrementa o valor do multiplicador 1 para que possamos tentar outros números do laço
      JMP comp_mult_p               ; pulamos para realizar uma nova comparacao do while

      eh_igual: 
      MOV byte[flag_encontramos_mult], 1; modificamos o valor da flag para verdadeiro

      fim_mult_p:
      POP rax                       ; desempilhamos nosso número inicial do topo da pilha para sabermos para onde dar RET
      RET

imprimir:
                                    ; esperamos que o número a ser impresso esteja em eax
      MOV rbx, 10 
      MOV r12b, 0                   ; iniciamos um contador neste registrador, sera usado na hora da impressao

      loop4:
      JMP divide_10                 ; pula para onde dividimos por 10 e pegamos o resto

      continua3:
      ADD edx, 0x30                 ; o valor de 0 em ASCII, vai ser usado para a conversão de inteiro em ASCII
      PUSH rdx                      ; guardamos o valor em ASCII na pilha, pois como estamos pegando o resto, o número a ser impresso está sendo "montado" do dígito menos significativo para o mais significativo
      CMP rax, 0                    ; se rax for zero, ou seja, o resultado da divisão, então já não temos mais números para pegar
      JNZ loop4                     ; se o quociente em rax for diferente de 0, voltamos para o loop4 para continuarmos pegando os dígitos
      MOV ecx, [MAX]                ; preparação para começarmos a imprimir o número, reiniciamos o contador por conta do loop5
      XOR rbx, rbx                  ; limpamos o registrador
      XOR rdx, rdx                  ; mesma coisa do anterior

      loop5:
      POP rax                       ; retiramos os números a serem impressos na ordem 
      MOV [digito], ax
      JMP imprimir_digito           ; vai para a parte da subrotina que imprimi um dígito por vez
      continua4:
      DEC r12b                      ; como já imprimimos um dígito, decrementamos o contador
      JNZ loop5                     ; se não for 0, ainda temos dígitos para imprimir, então voltamos ao loop5
      XOR rcx, rcx
      XOR rsi, rsi
      RET                           ; se todos os dígitos já foram impressos, saímos da subrotina

      divide_10:
      XOR edx, edx                  ; para não causar problemas 
      DIV rbx                       ; divide o valor guardado em rax, o número a ser impresso, por 10. O que nos interessa, o resto, está em eax. O quociente está em edx
      INC r12b                      ; vamos incrementando a medida que separamos mais digitos, para saber exatamente a quantidade de digitos no final
      JMP continua3                 ; voltamos para o loop

      imprimir_digito:
                                    ; sys_write(stdout, mensagem, tamanho)
      MOV rax, 1                    ; chamada de sistema sys_write
      MOV rsi, digito               ; endereço da mensagem
      MOV rdx, tamanho_impresso     ; tamanho da string de mensagem
      SYSCALL                       ; chamada ao sistema operacional
      JMP continua4

fim: 
                                    ; finaliza a exeução e volta para o shell
                                    ; void exit(int status);
      MOV rdi, 0                    ; primeiro parâmetro: o cóigo de saída (0 = sucesso)
      MOV rax, 60                   ; numero da syscall exit
      SYSCALL                       ; chamada ao SO
 
