/*
 * Agency.h
 *
 *  Created on: Jul 19, 2019
 *      Author: pedro
 */

#ifndef AGENCY_H_
#define AGENCY_H_
#include <string>

class Agency {
public:
	static constexpr int         AUSTRALIA_BUREAU_OF_METEOROLOGY = 36001;
	static constexpr const char* AUSTRALIA_BUREAU_OF_METEOROLOGY_DESCRIPTION = "Australia, Bureau of Meteorology (BoM)";

	static constexpr int         AUSTRALIA_JOINT_AUSTRALIAN_FACILITY_FOR_OCEAN_OBSERVING_SYSTEMS = 36002;
	static constexpr const char* AUSTRALIA_JOINT_AUSTRALIAN_FACILITY_FOR_OCEAN_OBSERVING_SYSTEMS_DESCRIPTION = "Australia, Joint         Australian Facility for Ocean Observing Systems (JAFOOS)";

	static constexpr int         AUSTRALIA_THE_COMMONWEALTH_SCIENTIFIC_AND_INDUSTRIAL_RESEARCH_ORGANISATION = 36003;
	static constexpr const char* AUSTRALIA_THE_COMMONWEALTH_SCIENTIFIC_AND_INDUSTRIAL_RESEARCH_ORGANISATION_DESCRIPTION = "Australia, the Commonwealth Scientific and Industrial Research Organisation (CSIRO)";

	static constexpr int         CANADA_MARINE_ENVIRONMENTAL_DATA_SERVICES = 124001;
	static constexpr const char* CANADA_MARINE_ENVIRONMENTAL_DATA_SERVICES_DESCRIPTION = "Canada, Marine Environmental Data Service (MEDS)";

	static constexpr int         CANADA_INSTITUTE_OF_OCEAN_SCIENCES = 124002;
	static constexpr const char* CANADA_INSTITUTE_OF_OCEAN_SCIENCES_DESCRIPTION = "Canada, Institute of Ocean Sciences (IOS)";

	static constexpr int         CHINA_THE_STATE_OCEANIC_ADMINISTRATION = 156001;
	static constexpr const char* CHINA_THE_STATE_OCEANIC_ADMINISTRATION_DESCRIPTION = "China, The State Oceanic Administration";

	static constexpr int         CHINA_SECOND_INSTITUTE_OF_OCEANOGRAPHY_STATE_OCEANIC_ADMINISTRATION = 156002;
	static constexpr const char* CHINA_SECOND_INSTITUTE_OF_OCEANOGRAPHY_STATE_OCEANIC_ADMINISTRATION_DESCRIPTION = "China, Second Institute of Oceanography, State Oceanic Administration";

	static constexpr int         CHINA_INSTITUTE_OF_OCEAN_TECHNOLOGY = 156003;
	static constexpr const char* CHINA_INSTITUTE_OF_OCEAN_TECHNOLOGY_DESCRIPTION = "China, Institute of Ocean Technology";

	static constexpr int         FRANCE_INSTITUT_DE_RECHERCHE_POUR_LE_DEVELOPPEMENT = 250001;
	static constexpr const char* FRANCE_INSTITUT_DE_RECHERCHE_POUR_LE_DEVELOPPEMENT_DESCRIPTION = "France, Institut de Recherche pour le Developpement (IRD)";

	static constexpr int         FRANCE_INSTITUT_FRANCAIS_DE_RECHERCHE_POUR_L_EXPLOITATION_DE_LA_MER = 250002;
	static constexpr const char* FRANCE_INSTITUT_FRANCAIS_DE_RECHERCHE_POUR_L_EXPLOITATION_DE_LA_MER_DESCRIPTION = "France, Institut Francais de Recherche pour l'Exploitation de la mer (IFREMER)";

	static constexpr int         GERMANY_BUNDESAMT_FUER_SEESCHIFFAHRT_UND_HYDROGRAPHIE = 276001;
	static constexpr const char* GERMANY_BUNDESAMT_FUER_SEESCHIFFAHRT_UND_HYDROGRAPHIE_DESCRIPTION = "Germany, Bundesamt fuer Seeschiffahrt und Hydrographie (BSH)";

	static constexpr int         GERMANY_INSTITUT_FUER_MEERESKUNDE_KIEL = 276002;
	static constexpr const char* GERMANY_INSTITUT_FUER_MEERESKUNDE_KIEL_DESCRIPTION = "Germany, Institut fuer Meereskunde, Kiel";

	static constexpr int         INDIA_NATIONAL_INSTITUTE_OF_OCEANOGRAPHY = 356001;
	static constexpr const char* INDIA_NATIONAL_INSTITUTE_OF_OCEANOGRAPHY_DESCRIPTION = "India, National Institute of Oceanography (NIO)";

	static constexpr int         INDIA_NATIONAL_INSTITUTE_FOR_OCEAN_TECHNOLOGY = 356002;
	static constexpr const char* INDIA_NATIONAL_INSTITUTE_FOR_OCEAN_TECHNOLOGY_DESCRIPTION = "India, National Institute for Ocean Technology (NIOT)";

	static constexpr int         INDIA_NATIONAL_CENTRE_FOR_OCEAN_INFORMATION_SERVICE = 356003;
	static constexpr const char* INDIA_NATIONAL_CENTRE_FOR_OCEAN_INFORMATION_SERVICE_DESCRIPTION = "India, National Centre for Ocean Information Service";

	static constexpr int         JAPAN_JAPAN_METEOROLOGICAL_AGENCY = 392001;
	static constexpr const char* JAPAN_JAPAN_METEOROLOGICAL_AGENCY_DESCRIPTION = "Japan, Japan Meteorological Agency (JMA)";

	static constexpr int         JAPAN_FRONTIER_OBSERVATIONAL_RESEARCH_SYSTEM_FOR_GLOBAL_CHANGE = 392002;
	static constexpr const char* JAPAN_FRONTIER_OBSERVATIONAL_RESEARCH_SYSTEM_FOR_GLOBAL_CHANGE_DESCRIPTION = "Japan, Frontier Observational Research System for Global Change";

	static constexpr int         JAPAN_JAPAN_MARINE_SCIENCE_AND_TECHNOLOGY_CENTRE = 392003;
	static constexpr const char* JAPAN_JAPAN_MARINE_SCIENCE_AND_TECHNOLOGY_CENTRE_DESCRIPTION = "Japan, Japan Marine Science and Technology Centre (JAMSTEC)";

	static constexpr int         REPUBLIC_OF_KOREA_SEOUL_NATIONAL_UNIVERSITY = 410001;
	static constexpr const char* REPUBLIC_OF_KOREA_SEOUL_NATIONAL_UNIVERSITY_DESCRIPTION = "Republic of Korea, Seoul National University";

	static constexpr int         REPUBLIC_OF_KOREA_KOREA_OCEAN_RESEARCH_AND_DEVELOPMENT_INSTITUTE = 410002;
	static constexpr const char* REPUBLIC_OF_KOREA_KOREA_OCEAN_RESEARCH_AND_DEVELOPMENT_INSTITUTE_DESCRIPTION = "Republic of Korea, Korea Ocean Research and Development Institute  (KORDI)";

	static constexpr int         REPUBLIC_OF_KOREA_METEOROLOGICAL_RESEARCH_INSTITUTE = 410003;
	static constexpr const char* REPUBLIC_OF_KOREA_METEOROLOGICAL_RESEARCH_INSTITUTE_DESCRIPTION = "Republic of Korea, Meteorological Research Institute";

	static constexpr int         NEW_CALEDONIA_INSTITUT_DE_RECHERCHE_POUR_LE_DEVELOPPEMENT = 540001;
	static constexpr const char* NEW_CALEDONIA_INSTITUT_DE_RECHERCHE_POUR_LE_DEVELOPPEMENT_DESCRIPTION = "New Caledonia, Institut de Recherche pour le Developpement (IRD)";

	static constexpr int         NEW_ZEALAND_NATIONAL_INSTITUTE_OF_WATER_AND_ATMOSPHERIC_RESEARCH = 554001;
	static constexpr const char* NEW_ZEALAND_NATIONAL_INSTITUTE_OF_WATER_AND_ATMOSPHERIC_RESEARCH_DESCRIPTION = "New Zealand, National Institute of Water and Atmospheric Research (NIWA)";

	static constexpr int         RUSSIAN_FEDERATION_STATE_OCEANOGRAPHIC_INSTITUTE_OF_ROSHYDROMET = 643001;
	static constexpr const char* RUSSIAN_FEDERATION_STATE_OCEANOGRAPHIC_INSTITUTE_OF_ROSHYDROMET_DESCRIPTION = "Russian Federation, State Oceanographic Institute of Roshydromet";

	static constexpr int         RUSSIAN_FEDERATION_FEDERAL_SERVICE_FOR_HYDROMETEOROLOGY_AND_ENVIRONMENTAL_MONITORING = 643002;
	static constexpr const char* RUSSIAN_FEDERATION_FEDERAL_SERVICE_FOR_HYDROMETEOROLOGY_AND_ENVIRONMENTAL_MONITORING_DESCRIPTION = "Russian Federation, Federal Service for Hydrometeorology and Environmental Monitoring";

	static constexpr int         SPAIN_INSTITUTO_ESPANOL_DE_OCEANOGRAFIA = 724001;
	static constexpr const char* SPAIN_INSTITUTO_ESPANOL_DE_OCEANOGRAFIA_DESCRIPTION = "Spain, Instituto Espanol de Oceanografia";

	static constexpr int         UNITED_KINGDOM_HYDROGRAPHIC_OFFICE = 826001;
	static constexpr const char* UNITED_KINGDOM_HYDROGRAPHIC_OFFICE_DESCRIPTION = "United Kingdom, Hydrographic Office";

	static constexpr int         UNITED_KINGDOM_SOUTHAMPTON_OCEANOGRAPHY_CENTRE = 826002;
	static constexpr const char* UNITED_KINGDOM_SOUTHAMPTON_OCEANOGRAPHY_CENTRE_DESCRIPTION = "United Kingdom, Southampton Oceanography Centre (SOC)";

	static constexpr int         USA_NOAA_ATLANTIC_OCEANOGRAPHIC_AND_METEOROLOGICAL_LABORATORIES = 840001;
	static constexpr const char* USA_NOAA_ATLANTIC_OCEANOGRAPHIC_AND_METEOROLOGICAL_LABORATORIES_DESCRIPTION = "USA, NOAA Atlantic Oceanographic and Meteorological Laboratories (AOML)";

	static constexpr int         USA_NOAA_PACIFIC_MARINE_ENVIRONMENTAL_LABORATORIES = 840002;
	static constexpr const char* USA_NOAA_PACIFIC_MARINE_ENVIRONMENTAL_LABORATORIES_DESCRIPTION = "USA, NOAA Pacific Marine Environmental Laboratories (PMEL)";

	static constexpr int         USA_SCRIPPS_INSTITUTION_OF_OCEANOGRAPHY = 840003;
	static constexpr const char* USA_SCRIPPS_INSTITUTION_OF_OCEANOGRAPHY_DESCRIPTION = "USA, Scripps Institution of Oceanography (SIO)";

	static constexpr int         USA_WOODS_HOLE_OCEANOGRAPHIC_INSTITUTION = 840004;
	static constexpr const char* USA_WOODS_HOLE_OCEANOGRAPHIC_INSTITUTION_DESCRIPTION = "USA, Woods Hole Oceanographic Institution (WHOI)";

	static constexpr int         USA_UNIVERSITY_OF_WASHINGTON = 840005;
	static constexpr const char* USA_UNIVERSITY_OF_WASHINGTON_DESCRIPTION = "USA, University of Washington";

	static constexpr int         USA_NAVAL_OCEANOGRAPHIC_OFFICE = 840006;
	static constexpr const char* USA_NAVAL_OCEANOGRAPHIC_OFFICE_DESCRIPTION = "USA, Naval Oceanographic Office";

	static constexpr int         MISSING_VALUE = 1048575;
	static constexpr const char* MISSING_VALUE_DESCRIPTION = "Missing value";
	Agency();
	virtual ~Agency();
	static std::string getAgencyDescription(int agencyCode);
};

#endif /* AGENCY_H_ */
