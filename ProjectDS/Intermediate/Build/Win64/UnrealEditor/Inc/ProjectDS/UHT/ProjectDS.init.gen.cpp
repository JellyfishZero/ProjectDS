// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeProjectDS_init() {}
	PROJECTDS_API UFunction* Z_Construct_UDelegateFunction_UPlayerStatusComp_BasicParamsValueChangedEvent__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_ProjectDS;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_ProjectDS()
	{
		if (!Z_Registration_Info_UPackage__Script_ProjectDS.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_UPlayerStatusComp_BasicParamsValueChangedEvent__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/ProjectDS",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0x0372D995,
				0xCC7AE79A,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_ProjectDS.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_ProjectDS.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_ProjectDS(Z_Construct_UPackage__Script_ProjectDS, TEXT("/Script/ProjectDS"), Z_Registration_Info_UPackage__Script_ProjectDS, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x0372D995, 0xCC7AE79A));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
