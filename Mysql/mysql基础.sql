-- mysql安装成功后，默认root用户密码为空，使用以下命令创建root用户的密码
mysqladmin -u root passward "hao123123"

-- 登陆
mysql -u root -p
password:hao123123

-- 查询数据库服务器中的所有数据库
show databases;

-- 在数据库服务器中创建一个数据库
create database test;

-- 选中某一个数据库进行操作
use test

-- 查看某个数据库中所有的数据表
show tables;

-- 创建一个数据表
mysql> CREATE TABLE pet(
    -> name VARCHAR(20),
    -> owner VARCHAR(20),
    -> species VARCHAR(20),
    -> sex CHAR(1),
    -> birth DATE,
    -> death DATE);

-- 查看创建好的数据表的结构
describe pet;

-- 查看表中的记录
select * from pet;

-- 往数据表中添加数据记录
INSERT INTO pet VALUES ('Puffball','Duane','hamster','f','1996-11-15',NULL);

-- 删除数据
delete from pet where name='Puffball';

-- 修改数据
update pet set name='旺财' where owner='Duane';

1399421607

-- 修改字段
alter table tb1 drop i; -- 删除
alter table tb1 add i int; -- 添加
alter table tb1 add i int first; -- 添加到第一列
alter table tb1 add i int after j; -- 添加到指定位置 
alter table tb1 modify c char(10); -- 调整c的类型
alter table tb1 change c i int; -- 调整c的名称和类型

-- 修改表明
alter table tb1 rename to tb2;



-- 导出导入文件权限设置
show variables like '%secure%'; -- 查看权限是否为NULL
参考：https://blog.csdn.net/qq_20417499/article/details/84621838?utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromMachineLearnPai2%7Edefault-1.control&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromMachineLearnPai2%7Edefault-1.control
[mysqld]
secure_file_priv = 