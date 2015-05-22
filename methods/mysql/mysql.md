# 用户及权限管理

``` sql
CREATE USER 'username'@'host' IDENTIFIED BY 'password';
GRANT ALL ON `database`.`table` TO 'username'@'host';
FLUSH PRIVILEGES;

-- host通配符: % 
```
