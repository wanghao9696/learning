
-- 登陆
mysql -uroot -phao123123

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