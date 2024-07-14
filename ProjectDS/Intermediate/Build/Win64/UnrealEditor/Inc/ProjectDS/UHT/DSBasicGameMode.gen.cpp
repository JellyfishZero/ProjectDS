// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ProjectDS/Public/GameMode/DSBasicGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDSBasicGameMode() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
PROJECTDS_API UClass* Z_Construct_UClass_ADSBasicGameMode();
PROJECTDS_API UClass* Z_Construct_UClass_ADSBasicGameMode_NoRegister();
UPackage* Z_Construct_UPackage__Script_ProjectDS();
// End Cross Module References

// Begin Class ADSBasicGameMode
void ADSBasicGameMode::StaticRegisterNativesADSBasicGameMode()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ADSBasicGameMode);
UClass* Z_Construct_UClass_ADSBasicGameMode_NoRegister()
{
	return ADSBasicGameMode::StaticClass();
}
struct Z_Construct_UClass_ADSBasicGameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "GameMode/DSBasicGameMode.h" },
		{ "ModuleRelativePath", "Public/GameMode/DSBasicGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ADSBasicGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ADSBasicGameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_ProjectDS,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ADSBasicGameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ADSBasicGameMode_Statics::ClassParams = {
	&ADSBasicGameMode::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x009002ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ADSBasicGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_ADSBasicGameMode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ADSBasicGameMode()
{
	if (!Z_Registration_Info_UClass_ADSBasicGameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ADSBasicGameMode.OuterSingleton, Z_Construct_UClass_ADSBasicGameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ADSBasicGameMode.OuterSingleton;
}
template<> PROJECTDS_API UClass* StaticClass<ADSBasicGameMode>()
{
	return ADSBasicGameMode::StaticClass();
}
ADSBasicGameMode::ADSBasicGameMode(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(ADSBasicGameMode);
ADSBasicGameMode::~ADSBasicGameMode() {}
// End Class ADSBasicGameMode

// Begin Registration
struct Z_CompiledInDeferFile_FID_unreal_ProjectDS_ProjectDS_Source_ProjectDS_Public_GameMode_DSBasicGameMode_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ADSBasicGameMode, ADSBasicGameMode::StaticClass, TEXT("ADSBasicGameMode"), &Z_Registration_Info_UClass_ADSBasicGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ADSBasicGameMode), 311286360U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_unreal_ProjectDS_ProjectDS_Source_ProjectDS_Public_GameMode_DSBasicGameMode_h_3487290514(TEXT("/Script/ProjectDS"),
	Z_CompiledInDeferFile_FID_unreal_ProjectDS_ProjectDS_Source_ProjectDS_Public_GameMode_DSBasicGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_unreal_ProjectDS_ProjectDS_Source_ProjectDS_Public_GameMode_DSBasicGameMode_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
