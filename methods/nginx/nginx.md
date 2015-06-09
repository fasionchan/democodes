# Nginx

## 使用入门

``` sh
# 安装nginx
apt-get install nginx

# 启动nginx
service nginx start

# 停止nginx
service nginx stop

# 重启nginx
service nginx restart

# 重新加载配置
service nginx reload

# 强制重新加载配置
service nginx force-reload

# 查看nginx运行状态
service nginx status

# 测试配置(合法性)
service nginx configtest
```

## 配置

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

# 服务器集群及权重(可选)
upstream dest-site.com {
    server 10.0.0.1:80 weight=1;
}
```
