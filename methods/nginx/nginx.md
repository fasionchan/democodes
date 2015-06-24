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

### 静态资源缓存

``` txt
server {
    listen 80;
    server_name some-site.com;

    root /some/path/to/site;

    # 缓存图片
    location ~ \.(jpg|png|jpeg|bmp|gif|swf)$ {
        root /some/path/to/site/images;
        if (-f $request_filename) {
            expires 7d;
            break;
        }
    }

    # 缓存样式
    location ~ \.(css)$ {
        root /some/path/to/site/css;
        if (-f $request_filename) {
            expires 3d;
            break;
        }
    }

    # 缓存脚本
    location ~ \.(js)$ {
        root /some/path/to/site/js;
        if (-f $request_filename) {
            expires 1d;
            break;
        }
    }
}
```

### 变量

|变量名|作用|
|:----|:----|
|$args|请求中的参数|
