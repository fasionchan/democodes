``` sh
# 统计连接数
netstat -ant | tail -n+3 | awk '{count[$6]++} END{for(stat in count) {print stat, count[stat]}}'
```
