-- Query 1
-- Find the ‘continents’, ‘countriesAndTerritories’, ‘year’, ‘month’ and ‘day’ where both the number of cases and deaths are higher than the average number of daily cases and daily deaths across all records in the table. Sort the results in descending order based on the highest number of cases and deaths.
SELECT C.continentExp, C.countriesAndTerritories, CD.year, CD.month, CD.day, CD.cases, CD.deaths
FROM CasesDeaths CD
JOIN Country C ON CD.countryTerritoryCode = C.countryTerritoryCode
WHERE CD.cases > (SELECT AVG(cases) FROM CasesDeaths) AND CD.deaths > (SELECT AVG(deaths) FROM CasesDeaths)
ORDER BY  CD.cases DESC, CD.deaths DESC;

- Query 2 
-- Find the top 3 ‘countriesAndTerritories’ within each continent with the highest number of  daily ‘cases’.  
WITH RankedCases AS (
    SELECT C.continentExp, C.countriesAndTerritories, CD.year, CD.month, CD.day, CD.cases,
ROW_NUMBER() OVER (PARTITION BY C.continentExp ORDER BY CD.cases DESC) AS rank
    FROM CasesDeaths CD
    JOIN Country C ON CD.countryTerritoryCode = C.countryTerritoryCode
)
SELECT continentExp, countriesAndTerritories, year, month, day, cases
FROM RankedCases
WHERE rank <= 3
ORDER BY continentExp,
rank;

-- Query 3
-- The number of cases and deaths by date, in descending date order, for each continent with the continent, date, number of cases, and number of deaths as columns) 
SELECT c.continentExp AS Continent,
       d.dateRep AS Date,
       SUM(cd.cases) AS Cases,
       SUM(cd.deaths) AS Deaths
FROM CasesDeaths cd
JOIN Country c ON cd.countryTerritoryCode = c.countryTerritoryCode
JOIN Date d ON cd.year = d.year AND cd.month = d.month AND cd.day = d.day
GROUP BY c.continentExp, d.dateRep
ORDER BY d.year DESC, d.month DESC, d.day DESC, c.continentExp;

-- Query 4
-- For each continent, find the monthly average ‘cases’ and ‘deaths’ of every ‘countriesAndTerritories’. Then display the monthly ‘cases’ and ‘deaths’ of the ‘countriesAndTerritories’ that higher than the monthly average. 
WITH MonthlyAverages AS (
    SELECT 
        c.continentExp AS Continent,
        c.countriesAndTerritories,
        AVG(cd.cases) AS MonthlyAverageCases,
        AVG(cd.deaths) AS MonthlyAverageDeaths
    FROM CasesDeaths cd
    JOIN Country c ON cd.countryTerritoryCode = c.countryTerritoryCode
    JOIN Date d ON cd.year = d.year AND cd.month = d.month AND cd.day = d.day
    GROUP BY c.continentExp, c.countriesAndTerritories
),
MonthlyCasesDeaths AS (
    SELECT 
        c.continentExp AS Continent,
        c.countriesAndTerritories,
        SUM(cd.cases) AS MonthlyCases,
        SUM(cd.deaths) AS MonthlyDeaths
    FROM CasesDeaths cd
    JOIN Country c ON cd.countryTerritoryCode = c.countryTerritoryCode
    JOIN Date d ON cd.year = d.year AND cd.month = d.month AND cd.day = d.day
    GROUP BY c.continentExp, c.countriesAndTerritories
)
SELECT m.Continent, m.countriesAndTerritories, m.MonthlyAverageCases,
    m.MonthlyAverageDeaths, cd.MonthlyCases, cd.MonthlyDeaths
FROM MonthlyAverages m
JOIN MonthlyCasesDeaths cd ON m.Continent = cd.Continent 
				AND m.countriesAndTerritories = cd.countriesAndTerritories
WHERE 
    cd.MonthlyCases > m.MonthlyAverageCases
    OR cd.MonthlyDeaths > m.MonthlyAverageDeaths
ORDER BY m.Continent, m.countriesAndTerritories;

-- Query 5
-- The total number of cases and deaths as a percentage of the population, for each country with
‘country’, ‘% cases of population’, ‘% deaths of population as columns’.
SELECT c.countriesAndTerritories AS Country,
       (CAST(SUM(cd.cases) AS FLOAT) / c.popData2022 * 100) AS "% cases of population",
       (CAST(SUM(cd.deaths) AS FLOAT) / c.popData2022 * 100) AS "% deaths of population"
FROM CasesDeaths cd
JOIN Country c ON cd.countryTerritoryCode = c.countryTerritoryCode
GROUP BY c.countriesAndTerritories, c.popData2022;

-- Query 6
-- A descending list of the top 10 countries, by percentage total deaths out of total cases in that country (with country name and % deaths of country cases as columns)
SELECT c.countriesAndTerritories AS Country,
       (CAST(SUM(cd.deaths) AS FLOAT) / SUM(cd.cases) * 100) AS "% deaths of country cases"
FROM CasesDeaths cd
JOIN Country c ON cd.countryTerritoryCode = c.countryTerritoryCode
GROUP BY c.countriesAndTerritories
ORDER BY "% deaths of country cases" DESC
LIMIT 10;

-- Query 7
-- The date against a cumulative running total of the number of deaths by day and cases by day for the United State of America 
WITH USA_CasesDeaths AS (
    SELECT d.year AS year, d.month AS month, d.day AS day,
        SUM(cd.cases) AS USA_daily_cases,
        SUM(cd.deaths) AS USA_daily_deaths
    FROM CasesDeaths cd
    JOIN Country c ON cd.countryTerritoryCode = c.countryTerritoryCode
    JOIN Date d ON cd.year = d.year AND cd.month = d.month AND cd.day = d.day
    WHERE c.countriesAndTerritories = 'United_States_of_America'
    GROUP BY d.year, d.month, d.day
    ORDER BY d.year, d.month, d.day
),
USA_Cumulative AS (
    SELECT year, month, day,
        USA_daily_cases,
        SUM(USA_daily_cases) OVER (ORDER BY year, month, day) AS USA_cumulative_cases,
        USA_daily_deaths,
        SUM(USA_daily_deaths) OVER (ORDER BY year, month, day) AS USA_cumulative_deaths
    FROM USA_CasesDeaths
)
SELECT year, month, day, USA_daily_cases, USA_cumulative_cases, USA_daily_deaths, USA_cumulative_deaths
FROM USA_Cumulative
ORDER BY year, month, day; 

-- Visualization
-- Plotting the top 10 countries in terms of overall cumulative deaths only. 
SELECT c.countriesAndTerritories AS Country,
       SUM(cd.deaths) AS CumulativeDeaths
FROM CasesDeaths cd
JOIN Country c ON cd.countryTerritoryCode = c.countryTerritoryCode
GROUP BY c.countriesAndTerritories
ORDER BY CumulativeDeaths DESC
LIMIT 10; 

-- Produce a graph that has a date on the horizontal axis and the cumulative number of deaths by country on the vertical axis, representing the top 10 countries in terms of overall cumulative deaths only 
WITH CumulativeDeaths AS (
    SELECT cd.countryTerritoryCode, c.countriesAndTerritories AS country, cd.year, cd.month, cd.day,
        SUM(cd.deaths) OVER (PARTITION BY cd.countryTerritoryCode ORDER BY cd.year, cd.month, cd.day) AS cumulative_deaths
    FROM CasesDeaths cd
    JOIN Country c ON cd.countryTerritoryCode = c.countryTerritoryCode
    JOIN Date d ON cd.year = d.year AND cd.month = d.month AND cd.day = d.day
),

MaxCumulativeDeaths AS (
    SELECT countryTerritoryCode, MAX(cumulative_deaths) AS max_cumulative_deaths
    FROM CumulativeDeaths
    GROUP BY countryTerritoryCode
)

SELECT cd.country, cd.year, cd.month, cd.day, cd.cumulative_deaths
FROM CumulativeDeaths cd
JOIN (
    SELECT countryTerritoryCode, max_cumulative_deaths 
    FROM MaxCumulativeDeaths 
    ORDER BY max_cumulative_deaths DESC 
    LIMIT 10
) top_countries
ON cd.countryTerritoryCode = top_countries.countryTerritoryCode
ORDER BY top_countries.max_cumulative_deaths DESC, cd.year, cd.month, cd.day;
