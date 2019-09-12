/*
 * DataQuality.h
 *
 *  Created on: Jul 19, 2019
 *      Author: pedro
 */

#ifndef INCLUDE_DATAQUALITY_H_
#define INCLUDE_DATAQUALITY_H_
#include <string>

class DataQuality {
public:
static constexpr  int         DATA_NOT_SUSPECT = 0;
static constexpr const char*  DATA_NOT_SUSPECT_DESCRIPTION = "Data Not Suspect";

static constexpr  int         DATA_SLIGHTLY_SUSPECT = 1;
static constexpr const char*  DATA_SLIGHTLY_SUSPECT_DESCRIPTION = "Data Slightly Suspect";

static constexpr  int         DATA_HIGHLY_SUSPECT = 2;
static constexpr const char*  DATA_HIGHLY_SUSPECT_DESCRIPTION = "Data Highly Suspect";

static constexpr  int         DATA_UNFIT_FOR_USE = 3;
static constexpr const char*  DATA_UNFIT_FOR_USE_DESCRIPTION = "Data Unfit For Use";
	DataQuality();
	virtual ~DataQuality();
	static std::string getDataQualityDescription(int);

};

#endif /* INCLUDE_DATAQUALITY_H_ */
