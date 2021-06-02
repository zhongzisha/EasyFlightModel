// Copyright 2016 Mookie. All Rights Reserved.

#include "flightmodel.h"
#include "flightmodelcomponent.h"

FVector UeasyFM::GetWind_Implementation(FVector Location) const {
	return Wind;
}

float UeasyFM::GetAirDensity_Implementation(FVector Location) const {
	if (VariesWithAltitude) {
		float airmp = SeaLevelAirDensity/GetCurveValue(AirDensityCurve, 0, SeaLevelAirDensity);

		return AirDensityCurve->GetFloatValue((Location.Z+GetWorld()->OriginLocation.Z) / WorldScale)*airmp;
	}
	else {
		return SeaLevelAirDensity;
	}
}

float UeasyFM::GetSpeedOfSound_Implementation(FVector Location) const {
	if (VariesWithAltitude) {
		float soundvmp = SeaLevelSpeedOfSound / GetCurveValue(SpeedOfSoundCurve, 0, SeaLevelSpeedOfSound);

		return SpeedOfSoundCurve->GetFloatValue((Location.Z+GetWorld()->OriginLocation.Z) / WorldScale)*WorldScale*soundvmp;
	}
	else {
		return SeaLevelSpeedOfSound*WorldScale;
	}
}