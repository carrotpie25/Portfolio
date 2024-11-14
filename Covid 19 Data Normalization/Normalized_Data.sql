-- Create country, date and CasesDeaths tables
CREATE TABLE Country (
    countryTerritoryCode TEXT PRIMARY KEY,
    countriesAndTerritories TEXT,
    geoId TEXT,
    continentExp TEXT,
    popData2022 INTEGER
);

CREATE TABLE Date (
    year INTEGER,
    month INTEGER,
    day INTEGER,
    dateRep TEXT,
    PRIMARY KEY (year, month, day)
);

CREATE TABLE CasesDeaths (
    countryTerritoryCode TEXT,
    year INTEGER,
    month INTEGER,
    day INTEGER,
    cases INTEGER,
    deaths INTEGER,
    PRIMARY KEY (countryTerritoryCode, year, month, day),
    FOREIGN KEY (countryTerritoryCode) REFERENCES Country(countryTerritoryCode),
    FOREIGN KEY (year, month, day) REFERENCES Date(year, month, day)
);

-- Insert data into country, date and CasesDeaths tables
INSERT INTO Country (countryTerritoryCode, countriesAndTerritories, geoId, continentExp, popData2022)
SELECT DISTINCT countryTerritoryCode, countriesAndTerritories, geoId, continentExp, popData2022
FROM cw2_dataset;

INSERT INTO Date (year, month, day, dateRep)
SELECT DISTINCT year, month, day, dateRep
FROM cw2_dataset;

INSERT INTO CasesDeaths (countryTerritoryCode, year, month, day, cases, deaths)
SELECT countryTerritoryCode, year, month, day, cases, deaths
FROM cw2_dataset;
