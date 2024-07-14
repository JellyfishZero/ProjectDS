// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ProjectDS/Public/DSGameInstance.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDSGameInstance() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_UGameInstance();
PROJECTDS_API UClass* Z_Construct_UClass_UDSGameInstance();
PROJECTDS_API UClass* Z_Construct_UClass_UDSGameInstance_NoRegister();
UPackage* Z_Construct_UPackage__Script_ProjectDS();
// End Cross Module References

// Begin Class UDSGameInstance
void UDSGameInstance::StaticRegisterNativesUDSGameInstance()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UDSGameInstance);
UClass* Z_Construct_UClass_UDSGameInstance_NoRegister()
{
	return UDSGameInstance::StaticClass();
}
struct Z_Construct_UClass_UDSGameInstance_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "DSGameInstance.h" },
		{ "ModuleRelativePath", "Public/DSGameInstance.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDSGameInstance>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UDSGameInstance_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UGameInstance,
	(UObject* (*)())Z_Construct_UPackage__Script_ProjectDS,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDSGameInstance_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UDSGameInstance_Statics::ClassParams = {
	&UDSGameInstance::StaticClass,
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
	0x009000A8u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDSGameInstance_Statics::Class_MetaDataParams), Z_Construct_UClass_UDSGameInstance_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UDSGameInstance()
{
	if (!Z_Registration_Info_UClass_UDSGameInstance.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDSGameInstance.OuterSingleton, Z_Construct_UClass_UDSGameInstance_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UDSGameInstance.OuterSingleton;
}
template<> PROJECTDS_API UClass* StaticClass<UDSGameInstance>()
{
	return UDSGameInstance::StaticClass();
}
UDSGameInstance::UDSGameInstance(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UDSGameInstance);
UDSGameInstance::~UDSGameInstance() {}
// End Class UDSGameInstance

// Begin Registration
struct Z_CompiledInDeferFile_FID_unreal_ProjectDS_ProjectDS_Source_ProjectDS_Public_DSGameInstance_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDSGameInstance, UDSGameInstance::StaticClass, TEXT("UDSGameInstance"), &Z_Registration_Info_UClass_UDSGameInstance, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDSGameInstance), 715986497U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_unreal_ProjectDS_ProjectDS_Source_ProjectDS_Public_DSGameInstance_h_273925119(TEXT("/Script/ProjectDS"),
	Z_CompiledInDeferFile_FID_unreal_ProjectDS_ProjectDS_Source_ProjectDS_Public_DSGameInstance_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_unreal_ProjectDS_ProjectDS_Source_ProjectDS_Public_DSGameInstance_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
