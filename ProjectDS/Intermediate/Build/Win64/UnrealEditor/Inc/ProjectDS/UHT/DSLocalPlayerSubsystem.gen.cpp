// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ProjectDS/Public/SubSystem/LocalPlayerSubsystem/DSLocalPlayerSubsystem.h"
#include "Runtime/Engine/Classes/Engine/LocalPlayer.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDSLocalPlayerSubsystem() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_ULocalPlayerSubsystem();
PROJECTDS_API UClass* Z_Construct_UClass_UDSLocalPlayerSubsystem();
PROJECTDS_API UClass* Z_Construct_UClass_UDSLocalPlayerSubsystem_NoRegister();
UPackage* Z_Construct_UPackage__Script_ProjectDS();
// End Cross Module References

// Begin Class UDSLocalPlayerSubsystem
void UDSLocalPlayerSubsystem::StaticRegisterNativesUDSLocalPlayerSubsystem()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UDSLocalPlayerSubsystem);
UClass* Z_Construct_UClass_UDSLocalPlayerSubsystem_NoRegister()
{
	return UDSLocalPlayerSubsystem::StaticClass();
}
struct Z_Construct_UClass_UDSLocalPlayerSubsystem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "SubSystem/LocalPlayerSubsystem/DSLocalPlayerSubsystem.h" },
		{ "ModuleRelativePath", "Public/SubSystem/LocalPlayerSubsystem/DSLocalPlayerSubsystem.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDSLocalPlayerSubsystem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UDSLocalPlayerSubsystem_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ULocalPlayerSubsystem,
	(UObject* (*)())Z_Construct_UPackage__Script_ProjectDS,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDSLocalPlayerSubsystem_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UDSLocalPlayerSubsystem_Statics::ClassParams = {
	&UDSLocalPlayerSubsystem::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDSLocalPlayerSubsystem_Statics::Class_MetaDataParams), Z_Construct_UClass_UDSLocalPlayerSubsystem_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UDSLocalPlayerSubsystem()
{
	if (!Z_Registration_Info_UClass_UDSLocalPlayerSubsystem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDSLocalPlayerSubsystem.OuterSingleton, Z_Construct_UClass_UDSLocalPlayerSubsystem_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UDSLocalPlayerSubsystem.OuterSingleton;
}
template<> PROJECTDS_API UClass* StaticClass<UDSLocalPlayerSubsystem>()
{
	return UDSLocalPlayerSubsystem::StaticClass();
}
UDSLocalPlayerSubsystem::UDSLocalPlayerSubsystem() {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UDSLocalPlayerSubsystem);
UDSLocalPlayerSubsystem::~UDSLocalPlayerSubsystem() {}
// End Class UDSLocalPlayerSubsystem

// Begin Registration
struct Z_CompiledInDeferFile_FID_unreal_ProjectDS_ProjectDS_Source_ProjectDS_Public_SubSystem_LocalPlayerSubsystem_DSLocalPlayerSubsystem_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDSLocalPlayerSubsystem, UDSLocalPlayerSubsystem::StaticClass, TEXT("UDSLocalPlayerSubsystem"), &Z_Registration_Info_UClass_UDSLocalPlayerSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDSLocalPlayerSubsystem), 558128479U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_unreal_ProjectDS_ProjectDS_Source_ProjectDS_Public_SubSystem_LocalPlayerSubsystem_DSLocalPlayerSubsystem_h_1379085451(TEXT("/Script/ProjectDS"),
	Z_CompiledInDeferFile_FID_unreal_ProjectDS_ProjectDS_Source_ProjectDS_Public_SubSystem_LocalPlayerSubsystem_DSLocalPlayerSubsystem_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_unreal_ProjectDS_ProjectDS_Source_ProjectDS_Public_SubSystem_LocalPlayerSubsystem_DSLocalPlayerSubsystem_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
