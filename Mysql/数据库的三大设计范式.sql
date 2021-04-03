-- 数据库三大设计范式


-- 1.第一范式
-- 1NF
-- 数据表中的所有字段都是不可分割的原子值
mysql> create table student2(
    -> id int primary key,
    -> name varchar(20),
    -> address varchar(20)
    -> );
mysql> insert into student2 values(1, '张三', '中国四川省成都市武侯区武侯大道100号')；
mysql> insert into student2 values(2, '李四', '中国四川省成都市武侯区武侯大道200号');
mysql> insert into student2 values(3, '王五', '中国四川省成都市武侯区武侯大道300号');
-- 字段值还能继续拆分的，不满足第一范式

mysql> create table student3(
    -> id int primary key,
    -> name varchar(20),
    -> country varchar(20),
    -> privence varchar(20),
    -> city varchar(20),
    -> details varchar(20)
    -> );
mysql> insert into student3 values(1, '张三', '中国', '四川省', '成都市', ' 侯区武侯大道100号');



-- 2.第二范式
-- 2NF
-- 必须满足第一范式的前提，第二范式要求，除主键外的每一列都必须完全依赖于主键
-- 如果要出现不完全依赖，只可能发生在联合主键的情况下
mysql> create table myorder(
    -> product_id int,
    -> customer_id int,
    -> product_name varchar(20),
    -> customer_name varchar(20),
    -> primary key(product_id,customer_id)
    -> );
-- 问题？
-- 除主键外的其他列，只依赖与主键的部分字段
-- 拆表
mysql> create table myorder(
	-> order_id int primary key,
    -> product_id int,
    -> customer_id int
    -> );

mysql> create table product(
	-> id int primary key,
    -> name varchar(20)
    -> );

mysql> create table custom(
	-> id int primary key,
    -> name varchar(20)
    -> );
-- 拆分三个表之后，就满足第二范式。



-- 3.第三范式
-- 3NF
-- 除必须先满足第二范式，除开主键列的其他列之间不能有传递依赖关系
mysql> create table myorder2(
    -> order_id int primary key,
    -> product_id int,
    -> customer_id int,
    -> customer_phone varchar(15)
    -> );
-- 应当拆分为
mysql> create table myorder2(
    -> order_id int primary key,
    -> product_id int,
    -> customer_id int
    -> );
mysql> create table myorder2(
    -> id int primary key,
    -> name varchar(20),
    -> phone varchar(15)
    -> );











