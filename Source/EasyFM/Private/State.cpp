// Copyright 2016 Mookie. All Rights Reserved.

#include "flightmodel.h"
#include "flightmodelcomponent.h"
#include "Serialization/MemoryReader.h"
#include "Serialization/MemoryWriter.h"

/*
TArray<uint8> UeasyFM::GetState(){
	TArray<uint8> Data;
	FMemoryWriter Writer(Data);
	FEasyFMArchive Ar = FEasyFMArchive(Writer,true);
	Serialize(Ar);
	return Data;
}

void UeasyFM::SetState(TArray<uint8> Data) {
	FMemoryReader Reader(Data);
	FEasyFMArchive Ar = FEasyFMArchive(Reader, true);
	Serialize(Ar);
}
*/

TArray<uint8> UeasyFM::GetState(){
	TArray<uint8> Data;
	FMemoryWriter Writer(Data, true);
	FEasyFMArchive Ar(Writer,true);
	Serialize(Ar);
	return Data;
}

void UeasyFM::SetState(TArray<uint8> Data) {
	FMemoryReader Reader(Data);
	FEasyFMArchive Ar(Reader, true);
	Serialize(Ar);
}