use tank;
drop table if exists damage;
create table damage(
	id varchar(18) primary key,
    attacker varchar(30) default "-1",
    victim varchar(30) default "-1",
    damages int default -1,
    damagetype int default -1,
    battletype int default -1,
    battleid int default -1,
    times timestamp default current_timestamp()
);

drop procedure if exists add_damage;
delimiter //
create procedure add_damage(in attackers varchar(30),in victims varchar(30),in damagess int,
	in damagetypes int,in battletypes int ,in battleids int,out result int)
begin
	call create_id(@ids);
    insert into damage(id,attacker,victim,damages,damagetype,battletype,battleid) values(
		@ids,attackers,victims,damagess,damagetypes,battletypes,battleids);
	set result = 0;
end
//
delimiter ;

drop procedure if exists damage_ave;-- 某个坦克平均伤害函数 --
delimiter //
create procedure damage_ave(in tanks varchar(30),out result decimal)
begin
	select AVG(m.n) into result from (select damages as n from damage where attacker=tanks) as m;
end
//
delimiter ;




drop procedure if exists create_id;-- 创建ID号
delimiter //
create procedure create_id(out card varchar(20))
begin
	declare time varchar(18);
    declare count varchar(4);
    set time=DATE_FORMAT(NOW(),'%Y%m%d%k%i%s');
	set count=(CEIL(RAND() * 8000) + 1000);
    set card=CONCAT(time,count);
end
//
delimiter ;


