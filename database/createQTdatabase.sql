create database qtdb character set utf8;
create user qtuser identified by 'qtuser';
create user qtuser@localhost identified by 'qtuser';
insert into mysql.db(host,Db,User,Select_priv,Insert_priv, Update_priv,Delete_priv,Create_priv, Drop_priv) values('localhost', 'qtdb', 'qtuser', 'Y','Y','Y','Y','Y','Y');
insert into mysql.db(host,Db,User,Select_priv,Insert_priv, Update_priv,Delete_priv,Create_priv, Drop_priv) values('%', 'qtdb', 'qtuser', 'Y','Y','Y','Y','Y','Y');
grant all privileges on qtdb.* to 'qtuser'@'localhost';
grant all privileges on qtdb.* to 'qtuser'@'%';