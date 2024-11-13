-- Query 1: Retrieve the names and email of flight staffs who are associated with a branch in a specific city 
SELECT fs.s_name, fs.s_email
FROM flightstaff fs
JOIN officebranch ob ON fs.branch_id = ob.branch_id
JOIN city c ON ob.city_id = c.city_id
WHERE c.city_name = 'Jakarta';

-- Query 2: Find average ticket price for each flight
SELECT 
    f.flight_id AS Flight_ID,
    AVG(tp.ticket_amount) AS Average_Ticket_Price
FROM flight f
JOIN ticketprice tp ON f.flight_id = tp.flight_id
GROUP BY f.flight_id;

-- Query 3: List the top 5 office branches with the highest number of staff 
SELECT ob.branch_name, COUNT(fs.staff_id) AS staff_count
FROM officebranch ob
LEFT JOIN flightstaff fs ON ob.branch_id = fs.branch_id
GROUP BY ob.branch_name
ORDER BY COUNT(fs.staff_id) DESC
FETCH FIRST 5 ROWS ONLY;

-- Query 4: List the name of the passengers who were on a specific flight, along with their city
SELECT p.p_name, c.city_name
FROM passenger p
JOIN contactdetail cd ON p.contact_detail_id = cd.contact_detail_id
JOIN city c ON cd.city_id = c.city_id
JOIN transaction t ON p.passenger_id = t.passenger_id
JOIN schedule s ON t.schedule_id = s.schedule_id
JOIN ticketprice tp ON s.ticket_price_id = tp.ticket_price_id
JOIN flight f ON tp.flight_id = f.flight_id
WHERE f.flight_code = 'MNO177';

-- Query 5: List all passengers under 30 along with their email, phone number, and age
SELECT
    p.p_name AS passenger_name,
    p.p_age AS age,
    cd.email AS email,
    cd.phone AS phone_number
FROM passenger p
JOIN contactdetail cd ON p.contact_detail_id = cd.contact_detail_id
WHERE p.p_age < 30;
