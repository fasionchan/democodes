# iptables

```
# 对外端口转发
iptables -t nat -A PREROUTING -p tcp -m tcp -d 192.168.0.1/32 --dport 8888 -j DNAT --to-destination 192.168.0.1:80

# 本地端口转发
iptables -t nat -A OUTPUT -p tcp -m tcp -d 127.0.0.1/32 --dport 8888 -j DNAT --to-destination 127.0.0.1:80
```
