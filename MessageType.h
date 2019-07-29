/*
 * MessageType.h
 *
 *  Created on: Jul 17, 2019
 *      Author: pedro
 */

#ifndef MESSAGETYPE_H_
#define MESSAGETYPE_H_

class MessageType {
public:

	static constexpr int OLD_MESSAGE_TYPE =63;
	static constexpr int MESSAGE_TYPE_1=1;
	static constexpr int MESSAGE_TYPE_2=2;
	static constexpr int MESSAGE_TYPE_3=3;
	static constexpr int MESSAGE_TYPE_4=4;
	MessageType();
	virtual ~MessageType();
};

#endif /* MESSAGETYPE_H_ */
