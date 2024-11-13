CREATE TABLE country (
    country_id   VARCHAR2(16) NOT NULL,
    country_name VARCHAR2(32) NOT NULL,
    PRIMARY KEY ( country_id )
);

CREATE TABLE city (
    city_id    VARCHAR2(16) NOT NULL,
    city_name  VARCHAR2(32) NOT NULL,
    country_id VARCHAR2(16) NOT NULL,
    PRIMARY KEY (city_id),
    CONSTRAINT city_country_fk FOREIGN KEY (country_id)
        REFERENCES country (country_id)
);

CREATE TABLE contactdetail (
    contact_detail_id VARCHAR2(16) NOT NULL,
    email             VARCHAR2(32) NOT NULL,
    phone             VARCHAR2(16) NOT NULL,
    address           VARCHAR2(64),
    city_id           VARCHAR2(16) NOT NULL,
    PRIMARY KEY (contact_detail_id),
    CONSTRAINT contactdetail_city_fk FOREIGN KEY (city_id)
        REFERENCES city (city_id)
);

CREATE TABLE officebranch (
    branch_id      VARCHAR2(16) NOT NULL,
    branch_name    VARCHAR2(16) NOT NULL,
    branch_address VARCHAR2(64) NOT NULL,
    city_id        VARCHAR2(16),
    PRIMARY KEY ( branch_id ),
    CONSTRAINT officebranch_city_fk FOREIGN KEY ( city_id )
        REFERENCES city ( city_id )
);

CREATE TABLE flightstaff (
    staff_id  VARCHAR2(16) NOT NULL,
    s_name    VARCHAR2(32) NOT NULL,
    s_role    VARCHAR2(32) NOT NULL,
    s_email   VARCHAR2(64) NOT NULL,
    branch_id VARCHAR2(16) NOT NULL,
    PRIMARY KEY ( staff_id ),
    CONSTRAINT flightstaff_officebranch_fk FOREIGN KEY ( branch_id )
        REFERENCES officebranch ( branch_id )
);

CREATE TABLE airplane (
    airplane_id       VARCHAR2(16) NOT NULL,
    airplane_no       VARCHAR2(32) NOT NULL,
    airplane_capacity VARCHAR2(32) NOT NULL,
    PRIMARY KEY ( airplane_id )
);

CREATE TABLE fine (
    fine_id     VARCHAR2(16) NOT NULL,
    fine_label  VARCHAR2(32) NOT NULL,
    fine_amount NUMBER NOT NULL,
    PRIMARY KEY ( fine_id )
);

CREATE TABLE flight (
    flight_id    VARCHAR2(16) NOT NULL,
    airport_from VARCHAR2(32) NOT NULL,
    airport_to   VARCHAR2(32) NOT NULL,
    flight_code  VARCHAR2(16) NOT NULL,
    PRIMARY KEY ( flight_id )
);

CREATE TABLE passenger (
    passenger_id      VARCHAR2(16) NOT NULL,
    p_name            VARCHAR2(32) NOT NULL,
    p_age             INTEGER,
    p_nationality     VARCHAR2(16),
    contact_detail_id VARCHAR2(16) NOT NULL,
    PRIMARY KEY ( passenger_id ),
    CONSTRAINT passenger_contactdetail_fk FOREIGN KEY ( contact_detail_id )
        REFERENCES contactdetail ( contact_detail_id )
);

CREATE TABLE sales (
    sales_id     VARCHAR2(16) NOT NULL,
    sales_label  VARCHAR2(32) NOT NULL,
    sales_amount NUMBER NOT NULL,
    PRIMARY KEY ( sales_id )
);

CREATE TABLE schedule (
    schedule_id     VARCHAR2(16) NOT NULL,
    take_off_time   TIMESTAMP,
    landing_time    TIMESTAMP,
    airplane_id     VARCHAR2(16),
    ticket_price_id VARCHAR2(16) NOT NULL,
    PRIMARY KEY ( schedule_id ),
    CONSTRAINT schedule_airplane_fk FOREIGN KEY ( airplane_id )
        REFERENCES airplane ( airplane_id ),
    CONSTRAINT schedule_ticketprice_fk FOREIGN KEY ( ticket_price_id )
        REFERENCES ticketprice ( ticket_price_id )
);

CREATE TABLE ticketprice (
    ticket_price_id VARCHAR2(16) NOT NULL,
    ticket_amount   NUMBER NOT NULL,
    flight_id       VARCHAR2(16) NOT NULL,
    PRIMARY KEY ( ticket_price_id ),
    CONSTRAINT ticketprice_flight_fk FOREIGN KEY ( flight_id )
        REFERENCES flight ( flight_id )
);

CREATE TABLE transaction (
    transaction_id         VARCHAR2(16) NOT NULL,
    fine_id           VARCHAR2(16) NOT NULL,
    sales_id         VARCHAR2(16) NOT NULL,
    passenger_id VARCHAR2(16),
    schedule_id   VARCHAR2(16),
    staff_id   VARCHAR2(16),
    PRIMARY KEY ( transaction_id ),
    CONSTRAINT transaction_fine_fk FOREIGN KEY ( fine_id )
        REFERENCES fine ( fine_id ),
    CONSTRAINT transaction_flightstaff_fk FOREIGN KEY ( staff_id )
        REFERENCES flightstaff ( staff_id ),
    CONSTRAINT transaction_passenger_fk FOREIGN KEY ( passenger_id )
        REFERENCES passenger ( passenger_id ),
    CONSTRAINT transaction_sales_fk FOREIGN KEY ( sales_id )
        REFERENCES sales ( sales_id ),
    CONSTRAINT transaction_schedule_fk FOREIGN KEY ( schedule_id )
        REFERENCES schedule ( schedule_id )
);




    

