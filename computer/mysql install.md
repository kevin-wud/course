# mysql安装和设置（centos7）

```shell
# 卸载mariadb
rpm -qa | grep mariadb
rpm -e --nodeps mariadb-libs-5.5.68-1.el7.x86_64
wget  http://dev.mysql.com/get/mysql80-community-release-el7-5.noarch.rpm
rpm  -ivh mysql80-community-release-el7-5.noarch.rpm

#安装mysql
yum install -y mysql mysql-devel mysql-community-server
#重新启动mysql服务
service mysqld restart
```

> 初次登陆mysql密码 grep 'password' /var/log/mysqld.log

```shell
mysql -u root -p
#输入登录密码
GRANT ALL PRIVILEGES ON *.* TO 'root'@'%' IDENTIFIED BY '设置的密码' WITH GRANT OPTION;
#修改属性
update user set host = '%' where user = 'root';
```

```shell
# 防火墙设置
firewall-cmd --list-all
firewall-cmd --permanent --add-port=3306/tcp
firewall-cmd --reload
```

