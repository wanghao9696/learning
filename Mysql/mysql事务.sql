
-- mysql事务

-- mysql中，事务其实就是一个最小的不可分割的工作单元。事务能够保证一个业务的完整性。
比如银行转账：
	a -> -100
	update user set money=money-100 where name='a';

	b -> +100
	update user set money=money+100 where name='b';

--实际的程序中，如果只有一条语句执行成功，而另外一条没有执行成功，出现数据前后不一致。

--多条sql语句，可能会有同事成功的要求，要么就同时失败，这就是事务要解决的问题



-- mysql中如何控制事务

1.mysql中默认是开启事务的

mysql> select @@autocommit;
+--------------+
| @@autocommit |
+--------------+
|            1 |
+--------------+
1 row in set (0.01 sec)
-- 上面的操作表明开启了mysql的自动提交
mysql> set @@autocommit=0;
+--------------+
| @@autocommit |
+--------------+
|            0 |
+--------------+
1 row in set (0.01 sec)
-- 上面的操作表明关闭了mysql的自动提交


-- 默认事务开启的作用是什么？
-- 当我们去执行一个sql语句的时候，效果会立即体现出来，且不能回滚

create database bank;

create table user(
	id int primary key,
	name varchar(20),
	money int
	);

insert into user values(1, 'a', 1000);


rollback;--事务回滚，提交之后不能事务回滚


begin;
start transaction;
--上边两条语句可以帮我们手动开启一个事务，在语句之前使用，仍可以使用事务回滚


commit;--手动提交，事务开启之后一旦提交，就不能事务回滚



-- 事务的四大特征
	A.原子性：事务是最小的单位，不可分割
	B.一致性：事务要求，同一事务中的sql语句，必须保证同时成功或者同时失败
	C.隔离性：事务1和事务2之间是有隔离的
	D.持久性：事务一旦结束，就不可以返回

-- 事务开启
	1.修改默认提交 set autocommit=0;
	2.begin;
	3.start transaction;

--事务手动提交
	commit;

--事务手动回滚
	rollback;



-- 事务的四种隔离性
1.read uncommitted;--读未提交的
如果事务a和事务b，a事务对数据进行操作，但是操作的过程中，事务没有被提交，但是b可以看见事务a操作的结果

2.read committed;--读已经提交的
3.repeatable read;--可以重复读
4.serializable;--串行化



















