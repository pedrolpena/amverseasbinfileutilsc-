/*
 * BinEncoder.cpp
 *
 *  Created on: Jul 27, 2019
 *      Author: pedro
 */

#include "BinEncoder.h"


BinEncoder::BinEncoder(XBTProfile &xBTProfile) {
	newMessageType = xBTProfile.getNewMessageType();
	encodeProfile(xBTProfile);
}

BinEncoder::BinEncoder() {
	newMessageType = 0;

}
BinEncoder::~BinEncoder() {

}



/**
 * <strong>(FXY)</strong>-This method flips the "endianes" of a BitSet
 * object and returns a BitSet object with flipped "endianess".
 *
 * @return <strong>(FXY)</strong>-This method flips the "endianes" of a
 * BitSet object and returns a BitSet object with flipped "endianess".
 */
stdex::bitvector BinEncoder::changeEndian(stdex::bitvector b) {
    bool temp;
    int width = b.size();
    for (int i = 0; i < width; i = i + 8) {
        for (int j = 0; j < 4; j++) {
            temp = b.test(i + j);
            b.set(i + j, b.test(i - j + 7));
            b.set(i - j + 7, temp);
        }//end for

    }//end for
    return b;
}

void BinEncoder::setBitWithinBits(stdex::bitvector &b, stdex::bitvector &subBits, int startPos) {

	unsigned int bitsRange = startPos + subBits.size() ;
	if ( b.size() < bitsRange ){   //make room for more bits
		unsigned int diff = bitsRange - b.size();
		for( unsigned int l = 0 ; l < diff ; l++){
			b.push_back(0);
		}//end for

	}//end if

    for (unsigned int i = 0; i < subBits.size(); i++) {
        if (subBits.test(i)) {
        	b.set(i + startPos, true);
        } else {
        	b.set(i + startPos, false);
        }
    }
}
/**
 * This method extracts the bits from the integer passed and stores it in a
 * BitSet object.
 *
 * @param b BitSet Object
 * @param intValue int to store
 * @param range an int[] that holds the start position and end position
 * where to insert the extracted bits.
 */
void BinEncoder::integerToBits(stdex::bitvector &b, int intValue, std::array<int,2> range) {
    if (range[0] == -1) {
        return;
    }
    int endPos;
    int startPos;
    startPos = range[0];
    endPos = range[1];
    int bitLength = endPos - startPos + 1;
    stdex::bitvector tempBS;
    tempBS = stdex::bitvector(bitLength);
    int bitZero;

    for (int i = 0; i < bitLength; i++) {
        bitZero = intValue & 0x01;
        intValue = intValue >> 1;
        if (bitZero == 1) {
            tempBS.set((bitLength - 1) - i, true);
        } else {
            tempBS.set((bitLength - 1) - i, false);
        }
    }
    setBitWithinBits(b, tempBS, startPos);
}

/**
 * This method extracts the bits from the string passed and stores it in a
 * BitSet object.
 *
 * @param b BitSet Object
 * @param stringValue String to store
 * @param range an int[] that holds the start position and end position
 * where to insert the extracted bits.
 */
void BinEncoder::stringToBits(stdex::bitvector &b, std::string stringValue, std::array<int,2> range) {
	if (range[0] == -1 || stringValue.size() < 1 || stringValue.compare("") == 0  ) {
         return;
     }


	int startPos = range[0];
	int stringLength = stringValue.size();
	stdex::bitvector bs;
	bs = stdex::bitvector( 8 * stringLength );
	char metaData='0';

     for( unsigned int i = 0 ; i <  stringValue.length() ; i++){

    	 for( int j = 0; j < 8 ; j++){
    		 metaData = ( ( stringValue[i] >> j ) & 0x01 );
    		 bs.set(8 * i + j , (bool)metaData);
    	 }//end for


     }//end for

      //= BitSet.valueOf(metaData);
     bs = changeEndian(bs);
     setBitWithinBits(b, bs, startPos);
}
/**
 * This method extracts the bits from the string passed and stores it in a
 * BitSet object.
 *
 * @param b BitSet Object
 * @param s String to store
 * @param range an int[] that holds the start position and end position
 * where to insert the extracted bits.
 * @param blocks The number of 40 bit blocks (5 characters) needed to encode
 * the string.
 */
void BinEncoder::encodeCommentBlocks(stdex::bitvector &b, std::string s, std::array<int,2> range, int blocks) {
	stdex::bitvector tmpBitSet;
	tmpBitSet = stdex::bitvector(8 * s.size());
    tmpBitSet.set(8, true);
    stringToBits(b, s, range);
}
/**
 * takes an XBTProfile object and creates a SEAS binary XBT profile
 *
 * @param xBTProfile an XBTProfile object
 */
void BinEncoder::encodeProfile(XBTProfile &xBTProfile) {
    int numberOfRiderBlocks;
    int numberOfRiderEmailBlocks;
    int numberOfRiderInstitutionBlocks;
    int numberOfRiderPhoneBlocks;
    int timesReplicated;
    int start;
    int start0;
    std::array<int,2> range{-1, -1};

    integerToBits(bits, xBTProfile.getOldMessageType(), XBTProfileDataRanges::getDataLocation(XBTProfileDataRanges::OLD_MESSAGE_TYPE,newMessageType));

    stringToBits(bits, xBTProfile.getWMOId(),XBTProfileDataRanges::getDataLocation(XBTProfileDataRanges::WMOID,newMessageType));
    integerToBits(bits, xBTProfile.getNewMessageType(), XBTProfileDataRanges::getDataLocation(XBTProfileDataRanges::NEW_MESSAGE_TYPE,newMessageType));
    double latitude = std::round(xBTProfile.getLatitude() * 100000.0 + 9000000);
    integerToBits(bits, (int)latitude, XBTProfileDataRanges::getDataLocation(XBTProfileDataRanges::LATITUDE,newMessageType));
    double longitude = std::round(xBTProfile.getLongitude() * 100000.0 + 18000000);
    integerToBits(bits, (int)longitude, XBTProfileDataRanges::getDataLocation(XBTProfileDataRanges::LONGITUDE,newMessageType));
    stringToBits(bits, xBTProfile.getSoopLine(), XBTProfileDataRanges::getDataLocation(XBTProfileDataRanges::SOOP_LINE,newMessageType));
    integerToBits(bits, xBTProfile.getTransectNumber(), XBTProfileDataRanges::getDataLocation(XBTProfileDataRanges::TRANSECT_NUM,newMessageType));
    integerToBits(bits, xBTProfile.getSequenceNumber(), XBTProfileDataRanges::getDataLocation(XBTProfileDataRanges::SEQUENCE_NUM,newMessageType));
    integerToBits(bits, xBTProfile.getYear(), XBTProfileDataRanges::getDataLocation(XBTProfileDataRanges::YEAR,newMessageType));
    integerToBits(bits, xBTProfile.getMonth(), XBTProfileDataRanges::getDataLocation(XBTProfileDataRanges::MONTH,newMessageType));
    integerToBits(bits, xBTProfile.getDay(), XBTProfileDataRanges::getDataLocation(XBTProfileDataRanges::DAY,newMessageType));
    integerToBits(bits, xBTProfile.getHour(), XBTProfileDataRanges::getDataLocation(XBTProfileDataRanges::HOUR,newMessageType));
    integerToBits(bits, xBTProfile.getMinute(), XBTProfileDataRanges::getDataLocation(XBTProfileDataRanges::MINUTE,newMessageType));
    stringToBits(bits, xBTProfile.getShipName(), XBTProfileDataRanges::getDataLocation(XBTProfileDataRanges::SHIP_NAME,newMessageType));
    integerToBits(bits, xBTProfile.getLloyds(), XBTProfileDataRanges::getDataLocation(XBTProfileDataRanges::LLOYDS,newMessageType));
    //integerToBitsTest(bits,xBTProfile.getUniqueTag(),XBTProfileDataRanges.getUniqueTag(newMessageType));
    integerToBits(bits, xBTProfile.getSeasVersion(), XBTProfileDataRanges::getDataLocation(XBTProfileDataRanges::SEAS_VERSION,newMessageType));
    integerToBits(bits, xBTProfile.getProbeSerialNumber(), XBTProfileDataRanges::getDataLocation(XBTProfileDataRanges::PROBE_SERIAL_NUMBER,newMessageType));
    integerToBits(bits, xBTProfile.getThisDataIs(), XBTProfileDataRanges::getDataLocation(XBTProfileDataRanges::THIS_DATA_IS,newMessageType));
    integerToBits(bits, xBTProfile.getDataQuality(), XBTProfileDataRanges::getDataLocation(XBTProfileDataRanges::DATA_QUALITY,newMessageType));
    double launchHeight = std::round(xBTProfile.getLaunchHeight() * 100.0);
    integerToBits(bits, (int)launchHeight, XBTProfileDataRanges::getDataLocation(XBTProfileDataRanges::LAUNCH_HEIGHT,newMessageType));
    double shipDirection = std::round(xBTProfile.getShipDirection());
    integerToBits(bits, (int)shipDirection, XBTProfileDataRanges::getDataLocation(XBTProfileDataRanges::SHIP_DIRECTION,newMessageType));
    double shipSpeed = std::round(xBTProfile.getShipSpeed() * 100.0);
    integerToBits(bits, (int)shipSpeed, XBTProfileDataRanges::getDataLocation(XBTProfileDataRanges::SHIP_SPEED,newMessageType));
    integerToBits(bits, xBTProfile.getInstrumentType(), XBTProfileDataRanges::getDataLocation(XBTProfileDataRanges::INSTRUMENT_TYPE,newMessageType));
    integerToBits(bits, xBTProfile.getRecorderType(), XBTProfileDataRanges::getDataLocation(XBTProfileDataRanges::RECORDER_TYPE,newMessageType));
    integerToBits(bits, xBTProfile.getWindInstrumentType(), XBTProfileDataRanges::getDataLocation(XBTProfileDataRanges::WIND_INSTRUMENT_TYPE,newMessageType));
    double windDirection = xBTProfile.getWindDirection();
    integerToBits(bits, (int)windDirection, XBTProfileDataRanges::getDataLocation(XBTProfileDataRanges::WIND_DIRECTION,newMessageType));
    double windSpeed = std::round(xBTProfile.getWindSpeed() * 10.0);
    integerToBits(bits, (int)windSpeed , XBTProfileDataRanges::getDataLocation(XBTProfileDataRanges::WIND_SPEED,newMessageType));
    double dryBulbTemperature = std::round(xBTProfile.getDryBulbTemperature() * 10.0);
    integerToBits(bits, (int)dryBulbTemperature, XBTProfileDataRanges::getDataLocation(XBTProfileDataRanges::DRY_BULB_TEMPERATURE,newMessageType));
    integerToBits(bits, xBTProfile.getSeaSurfaceCurrentMeasurementMethod(), XBTProfileDataRanges::getDataLocation(XBTProfileDataRanges::SEA_SURFACE_CURRENT_MEASURING_METHOD,newMessageType));
    integerToBits(bits, xBTProfile.getSeaSurfaceCurrentDirection(), XBTProfileDataRanges::getDataLocation(XBTProfileDataRanges::SEA_SURFACE_CURRENT_DIRECTION,newMessageType));
    double seaSurfaceCurrentSpeed = std::round(xBTProfile.getSeaSurfaceCurrentSpeed() * 100.00);
    integerToBits(bits, (int)seaSurfaceCurrentSpeed, XBTProfileDataRanges::getDataLocation(XBTProfileDataRanges::SEA_SURFACE_CURRENT_SPEED,newMessageType));
    integerToBits(bits, xBTProfile.getTotalWaterDepth(), XBTProfileDataRanges::getDataLocation(XBTProfileDataRanges::TOTAL_WATER_DEPTH,newMessageType));
    integerToBits(bits, xBTProfile.getAgencyOwner(), XBTProfileDataRanges::getDataLocation(XBTProfileDataRanges::AGENCY_OWNER,newMessageType));
    integerToBits(bits, xBTProfile.getXBTLauncherType(), XBTProfileDataRanges::getDataLocation(XBTProfileDataRanges::XBT_LAUNCHER_TYPE,newMessageType));
    stringToBits(bits, xBTProfile.getXBTRecorderSerialNumber(), XBTProfileDataRanges::getDataLocation(XBTProfileDataRanges::XBT_RECORDER_SERIAL_NUMBER,newMessageType));
    integerToBits(bits, xBTProfile.getXBTRecorderManufacturedYear(), XBTProfileDataRanges::getDataLocation(XBTProfileDataRanges::XBT_RECORDER_MANUFACTURE_YEAR,newMessageType));
    integerToBits(bits, xBTProfile.getXBTRecorderManufacturedMonth(), XBTProfileDataRanges::getDataLocation(XBTProfileDataRanges::XBT_RECORDER_MANUFACTURE_MONTH,newMessageType));
    integerToBits(bits, xBTProfile.getXBTRecorderManufacturedDay(), XBTProfileDataRanges::getDataLocation(XBTProfileDataRanges::XBT_RECORDER_MANUFACTURE_DAY,newMessageType));
    integerToBits(bits, xBTProfile.getXBTProbeManufacturedYear(), XBTProfileDataRanges::getDataLocation(XBTProfileDataRanges::XBT_PROBE_MANUFACTURE_YEAR,newMessageType));
    integerToBits(bits, xBTProfile.getXBTProbeManufacturedMonth(), XBTProfileDataRanges::getDataLocation(XBTProfileDataRanges::XBT_PROBE_MANUFACTURE_MONTH,newMessageType));
    integerToBits(bits, xBTProfile.getXBTProbeManufacturedDay(), XBTProfileDataRanges::getDataLocation(XBTProfileDataRanges::XBT_PROBE_MANUFACTURE_DAY,newMessageType));
    integerToBits(bits, xBTProfile.getNumberOfRiderInstitutionBlocks(), XBTProfileDataRanges::getDataLocation(XBTProfileDataRanges::NUMBER_OF_RIDER_INSTITUTION_BLOCKS,newMessageType));
    integerToBits(bits, xBTProfile.getNumberOfRiderEmailBlocks(), XBTProfileDataRanges::getDataLocation(XBTProfileDataRanges::NUMBER_OF_RIDER_EMAIL_BLOCKS,newMessageType));
    integerToBits(bits, xBTProfile.getNumberOfRiderPhoneBlocks(), XBTProfileDataRanges::getDataLocation(XBTProfileDataRanges::NUMBER_OF_RIDER_PHONE_BLOCKS,newMessageType));


    //********************Encode measurement points************************
    //int last = 0;
    int bitLen = XBTProfileDataRanges::getDataLocation(XBTProfileDataRanges::SEA_SURFACE_TEMPERATURE,newMessageType)[1] - XBTProfileDataRanges::getDataLocation(XBTProfileDataRanges::SEA_SURFACE_TEMPERATURE,newMessageType)[0] + 1;
    double scaleFactor = 2;
    int offset = 400;
    start = XBTProfileDataRanges::getDataLocation(XBTProfileDataRanges::TEMPERATURE_POINTS,newMessageType)[0];

    if (newMessageType == MessageType::MESSAGE_TYPE_4) {

        offset = 0;
        start = XBTProfileDataRanges::getDataLocation(XBTProfileDataRanges::RESISTANCE_POINTS,newMessageType)[0];

    }

    if (newMessageType == MessageType::MESSAGE_TYPE_1) {
        double seaDepth = xBTProfile.getSeaDepth();
        integerToBits(bits, (int)seaDepth, XBTProfileDataRanges::getDataLocation(XBTProfileDataRanges::SEA_DEPTH,newMessageType));
    }

    std::array<int,2> measurementPointsRange = {-1, -1};

    for (unsigned int i = 0; i < xBTProfile.getMeasurementPoints().size(); i++) {
        // we had to round here because the doubles were being
        // truncated to the wrong value

        double mp = std::round(xBTProfile.getMeasurementPoints()[i] * std::pow(10.0, scaleFactor)) + offset;
        measurementPointsRange[0] = start + i * bitLen;
        measurementPointsRange[1] = start + i * bitLen + bitLen - 1;
        integerToBits(bits, (int)mp , measurementPointsRange);
        //last = i;

    }


    //*************calculate Number of repeated fields.***************
    xBTProfile.setNumberOfRepeatedFields(1);

    if (xBTProfile.getThisDataIs() == 3) {
        xBTProfile.setNumberOfRepeatedFields(2);
    }// end if

    integerToBits(bits, xBTProfile.getNumberOfRepeatedFields(), XBTProfileDataRanges::getDataLocation(XBTProfileDataRanges::NUMBER_OF_REPEATED_FIELDS,newMessageType));

    //*************Compute timesReplicated****************************
    timesReplicated = xBTProfile.getMeasurementPoints().size();
    xBTProfile.setTimesReplicated(timesReplicated);
    integerToBits(bits, timesReplicated, XBTProfileDataRanges::getDataLocation(XBTProfileDataRanges::TIMES_REPLICATED,newMessageType));


    //**************Encode Rider Name*********************************
    start0 = XBTProfileDataRanges::getDataLocation(XBTProfileDataRanges::RIDER_NAMES,newMessageType)[0] + bitLen * timesReplicated;

    if (!xBTProfile.getRiderNames().empty() && xBTProfile.getRiderNames().length() > 0) {

        numberOfRiderBlocks = (int) std::ceil(((double) xBTProfile.getRiderNames().length()) / 5);

        if (numberOfRiderBlocks > 0) {
            integerToBits(bits, numberOfRiderBlocks, XBTProfileDataRanges::getDataLocation(XBTProfileDataRanges::NUMBER_OF_RIDER_BLOCKS,newMessageType));

            range[0] = start0;
            encodeCommentBlocks(bits, xBTProfile.getRiderNames(), range, numberOfRiderBlocks);
        }

    } else {
        numberOfRiderBlocks = 0;

    }

    xBTProfile.setNumberOfRiderBlocks(numberOfRiderBlocks);

    //***********************Encode Rider Email***********************
    if (!xBTProfile.getRiderEmails().empty()  && xBTProfile.getRiderEmails().length() > 0) {
        numberOfRiderEmailBlocks = (int) std::ceil(((double) xBTProfile.getRiderEmails().length()) / 5);

        if (numberOfRiderEmailBlocks > 0) {
            integerToBits(bits, numberOfRiderEmailBlocks,XBTProfileDataRanges::getDataLocation(XBTProfileDataRanges::NUMBER_OF_RIDER_EMAIL_BLOCKS,newMessageType));
            start0 = start0 + numberOfRiderBlocks * 40;
            range[0] = start0;
            encodeCommentBlocks(bits, xBTProfile.getRiderEmails(), range, numberOfRiderEmailBlocks);
        }
    } else {
        numberOfRiderEmailBlocks = 0;
        start0 = start0 + numberOfRiderBlocks * 40;
    }
    xBTProfile.setNumberOfRiderEmailBlocks(numberOfRiderEmailBlocks);

    //***********************Encode Rider Instituion********************
    if ( !xBTProfile.getRiderInstitutions().empty() && xBTProfile.getRiderInstitutions().length() > 0) {
        numberOfRiderInstitutionBlocks = (int) std::ceil(((double) xBTProfile.getRiderInstitutions().length()) / 5);
        if (numberOfRiderInstitutionBlocks > 0) {
            integerToBits(bits, numberOfRiderInstitutionBlocks,XBTProfileDataRanges::getDataLocation(XBTProfileDataRanges::NUMBER_OF_RIDER_INSTITUTION_BLOCKS,newMessageType));
            start0 = start0 + numberOfRiderEmailBlocks * 40;
            range[0] = start0;
            encodeCommentBlocks(bits, xBTProfile.getRiderInstitutions(), range, numberOfRiderInstitutionBlocks);
        }
    } else {
        numberOfRiderInstitutionBlocks = 0;
        start0 = start0 + numberOfRiderEmailBlocks * 40;
    }
    if (numberOfRiderInstitutionBlocks > 0) {
    }
    xBTProfile.setNumberOfRiderInstitutionBlocks(numberOfRiderInstitutionBlocks);

    //**************************Encode Rider Phone Number****************
    if ( !xBTProfile.getRiderPhones().empty() && xBTProfile.getRiderPhones().length() > 0) {
        numberOfRiderPhoneBlocks = (int) std::ceil(((double) xBTProfile.getRiderPhones().length()) / 5);
        if (numberOfRiderPhoneBlocks > 0) {
            integerToBits(bits, numberOfRiderPhoneBlocks, XBTProfileDataRanges::getDataLocation(XBTProfileDataRanges::NUMBER_OF_RIDER_PHONE_BLOCKS,newMessageType));
            start0 = start0 + numberOfRiderInstitutionBlocks * 40;
            range[0] = start0;

            encodeCommentBlocks(bits, xBTProfile.getRiderPhones(), range, numberOfRiderPhoneBlocks);
        }
    } else {
        numberOfRiderPhoneBlocks = 0;

    }
    xBTProfile.setNumberOfRiderPhoneBlocks(numberOfRiderPhoneBlocks);
    // calculate bits needed to make BitSet a multiple of 8
    unsigned int bitsNeeded =  std::abs(8 * (int)std::ceil(((double)getBitsSize())/(8.0)) - getBitsSize()) ;

    //calculate space left to fill for unsed part of last character block and some padding
    //type 1 and 2 messages are padded with ones and the rest are padded with zeros.

    unsigned int emptySpaces = 8;
    bool fillSet = false;

    //Type 1 and Type 2 messages were terminated differently
    if (newMessageType == MessageType::MESSAGE_TYPE_1 || newMessageType == MessageType::MESSAGE_TYPE_2)
    {
    	emptySpaces = 0;
    	fillSet = true;
    }

    if (numberOfRiderPhoneBlocks > 0){
    	emptySpaces =  8 * ( 5 * numberOfRiderPhoneBlocks - xBTProfile.getRiderPhones().length() ) ;
    }

    //pad the BitSet
    for(unsigned int i = 0 ; i < bitsNeeded + emptySpaces; i++){
    	bits.push_back(fillSet);
    }

   // Messages are terminated with a 1 so make the last bit a 1

   bits.set( bits.size() -1 , true);




}

/**
 * This method returns a string representation of the binary sequence in the
 * specified range in the bin file.
 *
 * @param start the bit position from which to start constructing the binary
 * sequence.
 * @param end the bit position from which to stop construction the binary
 * sequence.
 * @return <strong>(FXY)</strong>-This method returns a string
 * representation of the binary sequence in the specified range in the bin
 * file.
 */
std::string BinEncoder::getBinarySequence(int start, int end) {
	std::string str = "";
    for (int i = start; i <= end; i++) {

        if (bits.test(i)) {
            str += "1";
        }
        if (!bits.test(i)) {
            str += "0";
        }
        if ((i - start + 1) % 8 == 0) {
            str += " ";
        }

    }//end for
    return str;
}

int BinEncoder::getBitsSize(void) {
	return bits.size();
}

/**
 * This method calculates the CRC32 value or SEAS ID for the profile and
 * stores it in the profile.
 *
 * @param b the BitSet object that holds the profile.
 */
void BinEncoder::setMessageCRC(stdex::bitvector &b) {

	integerToBits(b, 0xFFFFFFFF,XBTProfileDataRanges::getDataLocation(XBTProfileDataRanges::UNIQUE_TAG, newMessageType));
	uint8_t x = 0;
	char buf[b.size()/8]={0};
	uint32_t crc;

	for (unsigned int i = 0; i < b.size(); i++) {

        x = x << 1 ;
		x |= b.test(i);

		if ((i + 1) % 8 == 0){
			buf[i/8] = x;
			x=0;
		}

	}//end for

	crc = computeCRC32(buf,b.size()/8);

	integerToBits(b, crc, XBTProfileDataRanges::getDataLocation(XBTProfileDataRanges::UNIQUE_TAG, newMessageType));
}

/**
 * This method accepts a String representing the filename that will be used
 * to create the binary file.
 *
 * @param outputFile the filename that will be used to create the binary
 * file.
 */
void BinEncoder::writeOutBinFile(std::string outputFile) {
	setMessageCRC(bits);
	std::ofstream fos;
	fos.open(outputFile, std::ios::binary | std::ios::out);
	char temp = 0;

	for (int i = 0; i < getBitsSize(); i++) {

		temp = temp << 1;
		temp |= bits.test(i);

		if ((i + 1) % 8 == 0) {
			fos.write(&temp, 1);
		}    //end if
	}    //end for

	fos.close();
}


/**
 * This method calculates the CRC32 lookup table on the fly
 * and returns the checksum. This way is slower but it's
 * easier to read. This method was posted on stackoverflow
 * https://stackoverflow.com/questions/26049150/calculate-a-32-bit-crc-lookup-table-in-c-c
 */
uint32_t BinEncoder::computeCRC32(char *buf, uint32_t len) {

    uint32_t val, crc;
    uint8_t i;

    crc = 0xFFFFFFFF;
    while(len--){
        val=(crc^*buf++)&0xFF;
        for(i=0; i<8; i++){
            val = val & 1 ? (val>>1)^0xEDB88320 : val>>1;
        }
        crc = val^crc>>8;
    }
    return crc^0xFFFFFFFF;
}
