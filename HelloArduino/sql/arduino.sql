-- web계정으로 온습도정보 관리

create table tb_dht(
    no number,
    h number not null,
    c number not null,
    hi number not null,
    time timestamp,
    constraint pk_tb_dht_no primary key(no)
);

create sequence seq_tb_dht_no;