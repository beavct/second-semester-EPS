#!/bin/bash

MENSAGEM_IP='Lista de IPs que estão conectados no servidor:'
MENSAGEM_SERVER='O servidor está fora do ar'
CONT=0
i=0
CPU_TOTAL=0

while [ 1 ]; do
    sleep $1
    let CONT=${CONT}+1
    CONT_SEGUNDOS=0

    #printa data na tela, telegram e arquivo indicado
    DATA="Data: $(date +"%d/%m/%Y")"
    echo ${DATA} | tee -a $2 
    curl -s --data "text=${DATA}" https://api.telegram.org/bot$4/sendMessage?chat_id=$5 1>/dev/null
    
    #printa hora na tela, telegram e arquivo indicado
    HORA="Hora: $(date +"%R:%S")"
    echo ${HORA} | tee -a $2 
    curl -s --data "text=$HORA" https://api.telegram.org/bot$4/sendMessage?chat_id=$5 1>/dev/null

    #printa os IPs se houver 
    if [  -n "$(netstat -anp 2>/dev/null | grep 45052 | uniq -u | grep ESTABELECIDA | awk '{printf "%ls\n", $4}')" ]; then 
        echo ${MENSAGEM_IP} | tee -a $2 
        curl -s --data "text=$MENSAGEM_IP" https://api.telegram.org/bot$4/sendMessage?chat_id=$5 1>/dev/null
        netstat -anp 2>/dev/null | grep 45052 | uniq -u | grep ESTABELECIDA | awk '{printf "%ls\n", $4}' | tee -a $2
        curl -s --data "text=$(netstat -anp 2>/dev/null | grep 45052 | uniq -u | grep ESTABELECIDA | awk '{printf "%ls\n", $4}')" https://api.telegram.org/bot$4/sendMessage?chat_id=$5 1>/dev/null

    fi

    #% de uso da CPU
    CPU_AGR=$(top -n 1 | head -n 3 | tail -n 1 | awk '{printf "%ls\n", $8}' | tr ',' '.')
    CPU_TOTAL=$(echo "${CPU_TOTAL}+${CPU_AGR}" | bc -l)
    MENSAGEM_CPU='Ociosidade da CPU: '${CPU_AGR}'%'

    if [ "$(echo "${CPU_AGR} > $3" | bc -l)" -eq 0 ];then 
        echo ${MENSAGEM_CPU}
        curl -s --data "text=$MENSAGEM_CPU" https://api.telegram.org/bot$4/sendMessage?chat_id=$5 1>/dev/null     
    fi

    echo ${MENSAGEM_CPU} >> $2
    let i=i+1   

    SECONDS=0
    #avisa caso o servidor esteja fora do ar
    while [ -z "$(netstat -anp 2>/dev/null | grep 45052 | grep OUÇA)" ];do
        sleep 1
        echo ${MENSAGEM_SERVER} | tee -a $2
        curl -s --data "text=$MENSAGEM_SERVER" https://api.telegram.org/bot$4/sendMessage?chat_id=$5 1>/dev/null

        #é como um backspace (somente no terminal)
        sleep 1
        printf '\e[A\e[K'
    done   
    let CONT_SEGUNDOS=${SECONDS}+${CONT_SEGUNDOS}

    #printa separacao no terminal, telegram e arquivo indicado
    echo ... | tee -a $2 
    curl -s --data "text=..." https://api.telegram.org/bot$4/sendMessage?chat_id=$5 1>/dev/null

    #a cada 100 intervalos
    if [ ${CONT} -eq 100 ]; then
        MEDIA=$(echo "${CPU_TOTAL}/${i}" | bc -l | awk '{printf "%.4s", $1}')
        echo '***' >> $2
        echo 'Média das 100 últimas medições de ociosidade de CPU: '${MEDIA}'%' >> $2
        echo 'Tempo em segundos que o servidor ficou fora do ar dentro dos últimos 100 intervalos de tempo:' ${CONT_SEGUNDOS}'s' >> $2
        echo '***' >> $2
        CONT_SEGUNDOS=0
        CONT=0  
        CPU_TOTAL=0    
        i=0  
    fi

done

exit 0
