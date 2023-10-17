-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Find crime scene description
SELECT * FROM crime_scene_reports
WHERE street = 'Humphrey Street'
AND day = 28;
-- THeft took place at 10.15 am 3 witnesses

--interview 3 witnss
SELECT name, transcript FROM interviews
WHERE year = 2021
AND month = 7 AND day = 28;
--WITNESS 1 RUTH: recommended to check security footage for the car license within 10 min of theft drive away
--WITNESS 2 : OVERHEARD in call: flight out of fiftyville 29/07/2021 ask other side of the call to book his flight EARLIEST FLIGHT
            --PHONECALL < a min
--WITNESS 3: Early in the morning at Leggett Street ATM withdrawing

--WITNESS 1---
-- Check the CAR footage around 10min of theft which is 10.15am
SELECT p.name, p.license_plate
FROM bakery_security_logs bsl
JOIN people p ON bsl.license_plate = p.license_plate
WHERE year = 2021 AND month = 7 AND day = 28
AND hour = 10 AND minute BETWEEN 15 AND 25 AND activity like 'exit';
-- 9 suspect here

---WITNESS 2--
SELECT p.name,p.phone_number,duration
FROM phone_calls pc
JOIN people p ON p.phone_number = pc.caller
WHERE year = 2021 AND month = 7 AND day = 28
AND duration < 60;
--9 sus here


--WITNESS 3----
-- Check the transaction at leggett street
SELECT account_number, transaction_type, amount
FROM atm_transactions
WHERE year = 2021 AND month = 7 AND day = 28
AND atm_location LIKE  'Leggett Street';
-- 8 person made withdraw

--check person with those account_numbers which is withdraw
SELECT p.name,p.passport_number
FROM people p
JOIN bank_accounts b ON p.id = b.person_id
JOIN atm_transactions atm ON atm.account_number = b.account_number
 WHERE year = 2021 AND month = 7 AND day = 28
AND atm_location LIKE  'Leggett Street' AND transaction_type like 'withdraw';
-- 8 more suspect

--COMMON NAME IN ALL 3 witness scenario
SELECT p.name
FROM bakery_security_logs bsl
JOIN people p ON bsl.license_plate = p.license_plate
WHERE year = 2021 AND month = 7 AND day = 28
AND hour = 10 AND minute BETWEEN 15 AND 25 AND activity like 'exit'
INTERSECT
SELECT p.name
FROM phone_calls pc
JOIN people p ON p.phone_number = pc.caller
WHERE year = 2021 AND month = 7 AND day = 28
AND duration < 60
INTERSECT
SELECT p.name
FROM people p
JOIN bank_accounts b ON p.id = b.person_id
JOIN atm_transactions atm ON atm.account_number = b.account_number
WHERE year = 2021 AND month = 7 AND day = 28
AND atm_location LIKE  'Leggett Street' AND transaction_type like 'withdraw';
--2 suspect left

--ANOTHER info from witness 2 about flight--
--check flight id
SELECT * FROM airports;
-- fiftyville airport id (8)

--Flights where depart at fiftyville airport next day
SELECT *
FROM flights
WHERE origin_airport_id = 8
AND year = 2021 AND month = 7 AND day = 29
ORDER BY hour;
-- EARIEST FLIGHT id(36) to New York City

--FIND name of suspect in flight 36
SELECT ppl.name
FROM passengers p
JOIN people ppl ON ppl.passport_number = p.passport_number
WHERE flight_id = 36 AND ppl.name in (SELECT p.name
                                        FROM bakery_security_logs bsl
                                        JOIN people p ON bsl.license_plate = p.license_plate
                                        WHERE year = 2021 AND month = 7 AND day = 28
                                        AND hour = 10 AND minute BETWEEN 15 AND 25 AND activity like 'exit'
                                        INTERSECT
                                        SELECT p.name
                                        FROM phone_calls pc
                                        JOIN people p ON p.phone_number = pc.caller
                                        WHERE year = 2021 AND month = 7 AND day = 28
                                        AND duration < 60
                                        INTERSECT
                                        SELECT p.name
                                        FROM people p
                                        JOIN bank_accounts b ON p.id = b.person_id
                                        JOIN atm_transactions atm ON atm.account_number = b.account_number
                                        WHERE year = 2021 AND month = 7 AND day = 28
                                        AND atm_location LIKE  'Leggett Street' AND transaction_type like 'withdraw');
-- 1 SUSPECT LEFT: Bruce <--- so he is the thief

--FIND ACCOMPLICE--
SELECT ppl2.name
FROM phone_calls p
JOIN people ppl1 ON ppl1.phone_number = p.caller
JOIN people ppl2 ON ppl2.phone_number = p.receiver
WHERE year = 2021 AND month = 7 AND day = 28 AND ppl1.name LIKE 'Bruce'
AND duration < 60;
--- robin--

