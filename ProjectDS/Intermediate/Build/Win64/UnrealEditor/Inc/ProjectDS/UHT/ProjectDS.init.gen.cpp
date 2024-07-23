// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeProjectDS_init() {}
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_ProjectDS;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_ProjectDS()
	{
		if (!Z_Registration_Info_UPackage__Script_ProjectDS.OuterSingleton)
		{
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/ProjectDS",
				nullptr,
				0,
				PKG_CompiledIn | 0x00000000,
				0xEE87E5A5,
				0x2F4140F6,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_ProjectDS.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_ProjectDS.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_ProjectDS(Z_Construct_UPackage__Script_ProjectDS, TEXT("/Script/ProjectDS"), Z_Registration_Info_UPackage__Script_ProjectDS, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0xEE87E5A5, 0x2F4140F6));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
