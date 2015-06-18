#!/usr/bin/env python
# -*- encoding=utf8 -*-

'''
FileName:   limits.py
Author:     Chen Yanfei
@contact:   fasionchan@gmail.com
@version:   $Id$

Description:

Changelog:

'''

## 用户资源限制配置文件

`/etc/security/limits.conf`

``` txt
*               soft    nofile      65535
*               hard    nofile      65535
root            soft    nofile      65535
root            hard    nofile      65535
```

修改配置后，必须重新登录才能生效。

## pam-limits

如果上述配置没有生效，则需要在`/etc/pam.d/common-session`中加上一下配置：

``` txt
session required pam_limits.so
```
