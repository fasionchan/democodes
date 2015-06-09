### 反向代理

``` txt
server {
    # 监听端口
    listen 80;
    # 代理对外域名
    server_name proxy-site.com;

    location / {
        # 转向服务器
        proxy_pass http://dest-site.com;
        proxy_redirect default;
    }
}

# 服务器集群及权重（可选）
upstream dest-site.com {
    server 10.0.0.1:80 weight=1;
}
```
