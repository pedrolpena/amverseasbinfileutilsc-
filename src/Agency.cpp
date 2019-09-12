/*
 * Agency.cpp
 *
 *  Created on: Jul 19, 2019
 *      Author: pedro
 */

#include "Agency.h"
constexpr int         AUSTRALIA_BUREAU_OF_METEOROLOGY = 36001;
constexpr const char* AUSTRALIA_BUREAU_OF_METEOROLOGY_DESCRIPTION = "Australia, Bureau of Meteorology (BoM)";

constexpr int         AUSTRALIA_JOINT_AUSTRALIAN_FACILITY_FOR_OCEAN_OBSERVING_SYSTEMS = 36002;
constexpr const char* AUSTRALIA_JOINT_AUSTRALIAN_FACILITY_FOR_OCEAN_OBSERVING_SYSTEMS_DESCRIPTION = "Australia, Joint         Australian Facility for Ocean Observing Systems (JAFOOS)";

constexpr int         AUSTRALIA_THE_COMMONWEALTH_SCIENTIFIC_AND_INDUSTRIAL_RESEARCH_ORGANISATION = 36003;
constexpr const char* AUSTRALIA_THE_COMMONWEALTH_SCIENTIFIC_AND_INDUSTRIAL_RESEARCH_ORGANISATION_DESCRIPTION = "Australia, the Commonwealth Scientific and Industrial Research Organisation (CSIRO)";

constexpr int         CANADA_MARINE_ENVIRONMENTAL_DATA_SERVICES = 124001;
constexpr const char* CANADA_MARINE_ENVIRONMENTAL_DATA_SERVICES_DESCRIPTION = "Canada, Marine Environmental Data Service (MEDS)";

constexpr int         CANADA_INSTITUTE_OF_OCEAN_SCIENCES = 124002;
constexpr const char* CANADA_INSTITUTE_OF_OCEAN_SCIENCES_DESCRIPTION = "Canada, Institute of Ocean Sciences (IOS)";

constexpr int         CHINA_THE_STATE_OCEANIC_ADMINISTRATION = 156001;
constexpr const char* CHINA_THE_STATE_OCEANIC_ADMINISTRATION_DESCRIPTION = "China, The State Oceanic Administration";

constexpr int         CHINA_SECOND_INSTITUTE_OF_OCEANOGRAPHY_STATE_OCEANIC_ADMINISTRATION = 156002;
constexpr const char* CHINA_SECOND_INSTITUTE_OF_OCEANOGRAPHY_STATE_OCEANIC_ADMINISTRATION_DESCRIPTION = "China, Second Institute of Oceanography, State Oceanic Administration";

constexpr int         CHINA_INSTITUTE_OF_OCEAN_TECHNOLOGY = 156003;
constexpr const char* CHINA_INSTITUTE_OF_OCEAN_TECHNOLOGY_DESCRIPTION = "China, Institute of Ocean Technology";

constexpr int         FRANCE_INSTITUT_DE_RECHERCHE_POUR_LE_DEVELOPPEMENT = 250001;
constexpr const char* FRANCE_INSTITUT_DE_RECHERCHE_POUR_LE_DEVELOPPEMENT_DESCRIPTION = "France, Institut de Recherche pour le Developpement (IRD)";

constexpr int         FRANCE_INSTITUT_FRANCAIS_DE_RECHERCHE_POUR_L_EXPLOITATION_DE_LA_MER = 250002;
constexpr const char* FRANCE_INSTITUT_FRANCAIS_DE_RECHERCHE_POUR_L_EXPLOITATION_DE_LA_MER_DESCRIPTION = "France, Institut Francais de Recherche pour l'Exploitation de la mer (IFREMER)";

constexpr int         GERMANY_BUNDESAMT_FUER_SEESCHIFFAHRT_UND_HYDROGRAPHIE = 276001;
constexpr const char* GERMANY_BUNDESAMT_FUER_SEESCHIFFAHRT_UND_HYDROGRAPHIE_DESCRIPTION = "Germany, Bundesamt fuer Seeschiffahrt und Hydrographie (BSH)";

constexpr int         GERMANY_INSTITUT_FUER_MEERESKUNDE_KIEL = 276002;
constexpr const char* GERMANY_INSTITUT_FUER_MEERESKUNDE_KIEL_DESCRIPTION = "Germany, Institut fuer Meereskunde, Kiel";

constexpr int         INDIA_NATIONAL_INSTITUTE_OF_OCEANOGRAPHY = 356001;
constexpr const char* INDIA_NATIONAL_INSTITUTE_OF_OCEANOGRAPHY_DESCRIPTION = "India, National Institute of Oceanography (NIO)";

constexpr int         INDIA_NATIONAL_INSTITUTE_FOR_OCEAN_TECHNOLOGY = 356002;
constexpr const char* INDIA_NATIONAL_INSTITUTE_FOR_OCEAN_TECHNOLOGY_DESCRIPTION = "India, National Institute for Ocean Technology (NIOT)";

constexpr int         INDIA_NATIONAL_CENTRE_FOR_OCEAN_INFORMATION_SERVICE = 356003;
constexpr const char* INDIA_NATIONAL_CENTRE_FOR_OCEAN_INFORMATION_SERVICE_DESCRIPTION = "India, National Centre for Ocean Information Service";

constexpr int         JAPAN_JAPAN_METEOROLOGICAL_AGENCY = 392001;
constexpr const char* JAPAN_JAPAN_METEOROLOGICAL_AGENCY_DESCRIPTION = "Japan, Japan Meteorological Agency (JMA)";

constexpr int         JAPAN_FRONTIER_OBSERVATIONAL_RESEARCH_SYSTEM_FOR_GLOBAL_CHANGE = 392002;
constexpr const char* JAPAN_FRONTIER_OBSERVATIONAL_RESEARCH_SYSTEM_FOR_GLOBAL_CHANGE_DESCRIPTION = "Japan, Frontier Observational Research System for Global Change";

constexpr int         JAPAN_JAPAN_MARINE_SCIENCE_AND_TECHNOLOGY_CENTRE = 392003;
constexpr const char* JAPAN_JAPAN_MARINE_SCIENCE_AND_TECHNOLOGY_CENTRE_DESCRIPTION = "Japan, Japan Marine Science and Technology Centre (JAMSTEC)";

constexpr int         REPUBLIC_OF_KOREA_SEOUL_NATIONAL_UNIVERSITY = 410001;
constexpr const char* REPUBLIC_OF_KOREA_SEOUL_NATIONAL_UNIVERSITY_DESCRIPTION = "Republic of Korea, Seoul National University";

constexpr int         REPUBLIC_OF_KOREA_KOREA_OCEAN_RESEARCH_AND_DEVELOPMENT_INSTITUTE = 410002;
constexpr const char* REPUBLIC_OF_KOREA_KOREA_OCEAN_RESEARCH_AND_DEVELOPMENT_INSTITUTE_DESCRIPTION = "Republic of Korea, Korea Ocean Research and Development Institute  (KORDI)";

constexpr int         REPUBLIC_OF_KOREA_METEOROLOGICAL_RESEARCH_INSTITUTE = 410003;
constexpr const char* REPUBLIC_OF_KOREA_METEOROLOGICAL_RESEARCH_INSTITUTE_DESCRIPTION = "Republic of Korea, Meteorological Research Institute";

constexpr int         NEW_CALEDONIA_INSTITUT_DE_RECHERCHE_POUR_LE_DEVELOPPEMENT = 540001;
constexpr const char* NEW_CALEDONIA_INSTITUT_DE_RECHERCHE_POUR_LE_DEVELOPPEMENT_DESCRIPTION = "New Caledonia, Institut de Recherche pour le Developpement (IRD)";

constexpr int         NEW_ZEALAND_NATIONAL_INSTITUTE_OF_WATER_AND_ATMOSPHERIC_RESEARCH = 554001;
constexpr const char* NEW_ZEALAND_NATIONAL_INSTITUTE_OF_WATER_AND_ATMOSPHERIC_RESEARCH_DESCRIPTION = "New Zealand, National Institute of Water and Atmospheric Research (NIWA)";

constexpr int         RUSSIAN_FEDERATION_STATE_OCEANOGRAPHIC_INSTITUTE_OF_ROSHYDROMET = 643001;
constexpr const char* RUSSIAN_FEDERATION_STATE_OCEANOGRAPHIC_INSTITUTE_OF_ROSHYDROMET_DESCRIPTION = "Russian Federation, State Oceanographic Institute of Roshydromet";

constexpr int         RUSSIAN_FEDERATION_FEDERAL_SERVICE_FOR_HYDROMETEOROLOGY_AND_ENVIRONMENTAL_MONITORING = 643002;
constexpr const char* RUSSIAN_FEDERATION_FEDERAL_SERVICE_FOR_HYDROMETEOROLOGY_AND_ENVIRONMENTAL_MONITORING_DESCRIPTION = "Russian Federation, Federal Service for Hydrometeorology and Environmental Monitoring";

constexpr int         SPAIN_INSTITUTO_ESPANOL_DE_OCEANOGRAFIA = 724001;
constexpr const char* SPAIN_INSTITUTO_ESPANOL_DE_OCEANOGRAFIA_DESCRIPTION = "Spain, Instituto Espanol de Oceanografia";

constexpr int         UNITED_KINGDOM_HYDROGRAPHIC_OFFICE = 826001;
constexpr const char* UNITED_KINGDOM_HYDROGRAPHIC_OFFICE_DESCRIPTION = "United Kingdom, Hydrographic Office";

constexpr int         UNITED_KINGDOM_SOUTHAMPTON_OCEANOGRAPHY_CENTRE = 826002;
constexpr const char* UNITED_KINGDOM_SOUTHAMPTON_OCEANOGRAPHY_CENTRE_DESCRIPTION = "United Kingdom, Southampton Oceanography Centre (SOC)";

constexpr int         USA_NOAA_ATLANTIC_OCEANOGRAPHIC_AND_METEOROLOGICAL_LABORATORIES = 840001;
constexpr const char* USA_NOAA_ATLANTIC_OCEANOGRAPHIC_AND_METEOROLOGICAL_LABORATORIES_DESCRIPTION = "USA, NOAA Atlantic Oceanographic and Meteorological Laboratories (AOML)";

constexpr int         USA_NOAA_PACIFIC_MARINE_ENVIRONMENTAL_LABORATORIES = 840002;
constexpr const char* USA_NOAA_PACIFIC_MARINE_ENVIRONMENTAL_LABORATORIES_DESCRIPTION = "USA, NOAA Pacific Marine Environmental Laboratories (PMEL)";

constexpr int         USA_SCRIPPS_INSTITUTION_OF_OCEANOGRAPHY = 840003;
constexpr const char* USA_SCRIPPS_INSTITUTION_OF_OCEANOGRAPHY_DESCRIPTION = "USA, Scripps Institution of Oceanography (SIO)";

constexpr int         USA_WOODS_HOLE_OCEANOGRAPHIC_INSTITUTION = 840004;
constexpr const char* USA_WOODS_HOLE_OCEANOGRAPHIC_INSTITUTION_DESCRIPTION = "USA, Woods Hole Oceanographic Institution (WHOI)";

constexpr int         USA_UNIVERSITY_OF_WASHINGTON = 840005;
constexpr const char* USA_UNIVERSITY_OF_WASHINGTON_DESCRIPTION = "USA, University of Washington";

constexpr int         USA_NAVAL_OCEANOGRAPHIC_OFFICE = 840006;
constexpr const char* USA_NAVAL_OCEANOGRAPHIC_OFFICE_DESCRIPTION = "USA, Naval Oceanographic Office";

constexpr int         MISSING_VALUE = 1048575;
constexpr const char* MISSING_VALUE_DESCRIPTION = "Missing value";


Agency::Agency() {
	// TODO Auto-generated constructor stub

}

Agency::~Agency() {
	// TODO Auto-generated destructor stub
}

std::string Agency::getAgencyDescription(int agencyCode) {
	const char * description = "Missing value";

	switch (agencyCode) {

	           case AUSTRALIA_BUREAU_OF_METEOROLOGY:
	                description = AUSTRALIA_BUREAU_OF_METEOROLOGY_DESCRIPTION;
	                break;

	            case AUSTRALIA_JOINT_AUSTRALIAN_FACILITY_FOR_OCEAN_OBSERVING_SYSTEMS:
	                description = AUSTRALIA_JOINT_AUSTRALIAN_FACILITY_FOR_OCEAN_OBSERVING_SYSTEMS_DESCRIPTION;
	                break;
	            case AUSTRALIA_THE_COMMONWEALTH_SCIENTIFIC_AND_INDUSTRIAL_RESEARCH_ORGANISATION:
	                description = AUSTRALIA_THE_COMMONWEALTH_SCIENTIFIC_AND_INDUSTRIAL_RESEARCH_ORGANISATION_DESCRIPTION;
	                break;
	            case CANADA_MARINE_ENVIRONMENTAL_DATA_SERVICES:
	                description = CANADA_MARINE_ENVIRONMENTAL_DATA_SERVICES_DESCRIPTION;
	                break;
	            case CHINA_THE_STATE_OCEANIC_ADMINISTRATION:
	                description = CHINA_THE_STATE_OCEANIC_ADMINISTRATION_DESCRIPTION;
	                break;
	            case CHINA_SECOND_INSTITUTE_OF_OCEANOGRAPHY_STATE_OCEANIC_ADMINISTRATION:
	                description = CHINA_SECOND_INSTITUTE_OF_OCEANOGRAPHY_STATE_OCEANIC_ADMINISTRATION_DESCRIPTION;
	                break;
	            case CHINA_INSTITUTE_OF_OCEAN_TECHNOLOGY:
	                description = CHINA_INSTITUTE_OF_OCEAN_TECHNOLOGY_DESCRIPTION;
	                break;
	            case FRANCE_INSTITUT_DE_RECHERCHE_POUR_LE_DEVELOPPEMENT:
	                description = FRANCE_INSTITUT_DE_RECHERCHE_POUR_LE_DEVELOPPEMENT_DESCRIPTION;
	                break;
	            case FRANCE_INSTITUT_FRANCAIS_DE_RECHERCHE_POUR_L_EXPLOITATION_DE_LA_MER:
	                description = FRANCE_INSTITUT_FRANCAIS_DE_RECHERCHE_POUR_L_EXPLOITATION_DE_LA_MER_DESCRIPTION;
	                break;
	            case GERMANY_BUNDESAMT_FUER_SEESCHIFFAHRT_UND_HYDROGRAPHIE:
	                description = GERMANY_BUNDESAMT_FUER_SEESCHIFFAHRT_UND_HYDROGRAPHIE_DESCRIPTION;
	                break;
	            case GERMANY_INSTITUT_FUER_MEERESKUNDE_KIEL:
	                description = GERMANY_INSTITUT_FUER_MEERESKUNDE_KIEL_DESCRIPTION;
	                break;
	            case INDIA_NATIONAL_INSTITUTE_OF_OCEANOGRAPHY:
	                description = INDIA_NATIONAL_INSTITUTE_OF_OCEANOGRAPHY_DESCRIPTION;
	                break;
	            case INDIA_NATIONAL_INSTITUTE_FOR_OCEAN_TECHNOLOGY:
	                description = INDIA_NATIONAL_INSTITUTE_FOR_OCEAN_TECHNOLOGY_DESCRIPTION;
	                break;
	            case INDIA_NATIONAL_CENTRE_FOR_OCEAN_INFORMATION_SERVICE:
	                description = INDIA_NATIONAL_CENTRE_FOR_OCEAN_INFORMATION_SERVICE_DESCRIPTION;
	                break;
	            case JAPAN_JAPAN_METEOROLOGICAL_AGENCY:
	                description = JAPAN_JAPAN_METEOROLOGICAL_AGENCY_DESCRIPTION;
	                break;
	            case JAPAN_FRONTIER_OBSERVATIONAL_RESEARCH_SYSTEM_FOR_GLOBAL_CHANGE:
	                description = JAPAN_FRONTIER_OBSERVATIONAL_RESEARCH_SYSTEM_FOR_GLOBAL_CHANGE_DESCRIPTION;
	                break;
	            case JAPAN_JAPAN_MARINE_SCIENCE_AND_TECHNOLOGY_CENTRE:
	                description = JAPAN_JAPAN_MARINE_SCIENCE_AND_TECHNOLOGY_CENTRE_DESCRIPTION;
	                break;
	            case REPUBLIC_OF_KOREA_SEOUL_NATIONAL_UNIVERSITY:
	                description = REPUBLIC_OF_KOREA_SEOUL_NATIONAL_UNIVERSITY_DESCRIPTION;
	                break;
	            case REPUBLIC_OF_KOREA_KOREA_OCEAN_RESEARCH_AND_DEVELOPMENT_INSTITUTE:
	                description = REPUBLIC_OF_KOREA_KOREA_OCEAN_RESEARCH_AND_DEVELOPMENT_INSTITUTE_DESCRIPTION;
	                break;
	            case REPUBLIC_OF_KOREA_METEOROLOGICAL_RESEARCH_INSTITUTE:
	                description = REPUBLIC_OF_KOREA_METEOROLOGICAL_RESEARCH_INSTITUTE_DESCRIPTION;
	                break;
	            case NEW_CALEDONIA_INSTITUT_DE_RECHERCHE_POUR_LE_DEVELOPPEMENT:
	                description = NEW_CALEDONIA_INSTITUT_DE_RECHERCHE_POUR_LE_DEVELOPPEMENT_DESCRIPTION;
	                break;
	            case NEW_ZEALAND_NATIONAL_INSTITUTE_OF_WATER_AND_ATMOSPHERIC_RESEARCH:
	                description = NEW_ZEALAND_NATIONAL_INSTITUTE_OF_WATER_AND_ATMOSPHERIC_RESEARCH_DESCRIPTION;
	                break;
	            case RUSSIAN_FEDERATION_STATE_OCEANOGRAPHIC_INSTITUTE_OF_ROSHYDROMET:
	                description = RUSSIAN_FEDERATION_STATE_OCEANOGRAPHIC_INSTITUTE_OF_ROSHYDROMET_DESCRIPTION;
	                break;
	            case RUSSIAN_FEDERATION_FEDERAL_SERVICE_FOR_HYDROMETEOROLOGY_AND_ENVIRONMENTAL_MONITORING:
	                description = RUSSIAN_FEDERATION_FEDERAL_SERVICE_FOR_HYDROMETEOROLOGY_AND_ENVIRONMENTAL_MONITORING_DESCRIPTION;
	                break;
	            case SPAIN_INSTITUTO_ESPANOL_DE_OCEANOGRAFIA:
	                description = SPAIN_INSTITUTO_ESPANOL_DE_OCEANOGRAFIA_DESCRIPTION;
	                break;
	            case UNITED_KINGDOM_HYDROGRAPHIC_OFFICE:
	                description = UNITED_KINGDOM_HYDROGRAPHIC_OFFICE_DESCRIPTION;
	                break;
	            case UNITED_KINGDOM_SOUTHAMPTON_OCEANOGRAPHY_CENTRE:
	                description = UNITED_KINGDOM_SOUTHAMPTON_OCEANOGRAPHY_CENTRE_DESCRIPTION;
	                break;
	            case USA_NOAA_ATLANTIC_OCEANOGRAPHIC_AND_METEOROLOGICAL_LABORATORIES:
	                description = USA_NOAA_ATLANTIC_OCEANOGRAPHIC_AND_METEOROLOGICAL_LABORATORIES_DESCRIPTION;
	                break;
	            case USA_NOAA_PACIFIC_MARINE_ENVIRONMENTAL_LABORATORIES:
	                description = USA_NOAA_PACIFIC_MARINE_ENVIRONMENTAL_LABORATORIES_DESCRIPTION;
	                break;
	            case USA_SCRIPPS_INSTITUTION_OF_OCEANOGRAPHY:
	                description = USA_SCRIPPS_INSTITUTION_OF_OCEANOGRAPHY_DESCRIPTION;
	                break;
	            case USA_WOODS_HOLE_OCEANOGRAPHIC_INSTITUTION:
	                description = USA_WOODS_HOLE_OCEANOGRAPHIC_INSTITUTION_DESCRIPTION;
	                break;
	            case USA_UNIVERSITY_OF_WASHINGTON:
	                description = USA_UNIVERSITY_OF_WASHINGTON_DESCRIPTION;
	                break;
	            case USA_NAVAL_OCEANOGRAPHIC_OFFICE:
	                description = USA_NAVAL_OCEANOGRAPHIC_OFFICE_DESCRIPTION;
	                break;
	            case MISSING_VALUE:
	                description = MISSING_VALUE_DESCRIPTION;
	                break;

	        }// end switch
	        return std::string(description);
}
