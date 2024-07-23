// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ProjectDS/Public/Controller/MainGamePC.h"
#include "EnhancedInput/Public/InputActionValue.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMainGamePC() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_APlayerController();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputMappingContext_NoRegister();
ENHANCEDINPUT_API UScriptStruct* Z_Construct_UScriptStruct_FInputActionValue();
PROJECTDS_API UClass* Z_Construct_UClass_AMainGamePC();
PROJECTDS_API UClass* Z_Construct_UClass_AMainGamePC_NoRegister();
UPackage* Z_Construct_UPackage__Script_ProjectDS();
// End Cross Module References

// Begin Class AMainGamePC Function Look
struct Z_Construct_UFunction_AMainGamePC_Look_Statics
{
	struct MainGamePC_eventLook_Parms
	{
		FInputActionValue Value;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* \xe6\x94\x9d\xe5\xbd\xb1\xe6\xa9\x9f\xe6\x97\x8b\xe8\xbd\x89 */" },
#endif
		{ "ModuleRelativePath", "Public/Controller/MainGamePC.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\x94\x9d\xe5\xbd\xb1\xe6\xa9\x9f\xe6\x97\x8b\xe8\xbd\x89" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Value;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMainGamePC_Look_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MainGamePC_eventLook_Parms, Value), Z_Construct_UScriptStruct_FInputActionValue, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Value_MetaData), NewProp_Value_MetaData) }; // 494646648
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMainGamePC_Look_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMainGamePC_Look_Statics::NewProp_Value,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMainGamePC_Look_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMainGamePC_Look_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMainGamePC, nullptr, "Look", nullptr, nullptr, Z_Construct_UFunction_AMainGamePC_Look_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMainGamePC_Look_Statics::PropPointers), sizeof(Z_Construct_UFunction_AMainGamePC_Look_Statics::MainGamePC_eventLook_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00440401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMainGamePC_Look_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMainGamePC_Look_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AMainGamePC_Look_Statics::MainGamePC_eventLook_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMainGamePC_Look()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMainGamePC_Look_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMainGamePC::execLook)
{
	P_GET_STRUCT_REF(FInputActionValue,Z_Param_Out_Value);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Look(Z_Param_Out_Value);
	P_NATIVE_END;
}
// End Class AMainGamePC Function Look

// Begin Class AMainGamePC
void AMainGamePC::StaticRegisterNativesAMainGamePC()
{
	UClass* Class = AMainGamePC::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "Look", &AMainGamePC::execLook },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AMainGamePC);
UClass* Z_Construct_UClass_AMainGamePC_NoRegister()
{
	return AMainGamePC::StaticClass();
}
struct Z_Construct_UClass_AMainGamePC_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "Controller/MainGamePC.h" },
		{ "ModuleRelativePath", "Public/Controller/MainGamePC.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DSGameInputContext_MetaData[] = {
		{ "Category", "MainGamePC" },
		{ "ModuleRelativePath", "Public/Controller/MainGamePC.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxPitchAngle_MetaData[] = {
		{ "Category", "MainGamePC" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\xe6\x94\x9d\xe5\xbd\xb1\xe6\xa9\x9f\xe8\xa7\x92\xe5\xba\xa6\xe9\x99\x90\xe5\x88\xb6*/" },
#endif
		{ "ModuleRelativePath", "Public/Controller/MainGamePC.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\x94\x9d\xe5\xbd\xb1\xe6\xa9\x9f\xe8\xa7\x92\xe5\xba\xa6\xe9\x99\x90\xe5\x88\xb6" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MinPitchAngle_MetaData[] = {
		{ "Category", "MainGamePC" },
		{ "ModuleRelativePath", "Public/Controller/MainGamePC.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LookAction_MetaData[] = {
		{ "Category", "InputAction" },
		{ "ModuleRelativePath", "Public/Controller/MainGamePC.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DSGameInputContext;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxPitchAngle;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MinPitchAngle;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_LookAction;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AMainGamePC_Look, "Look" }, // 628868392
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMainGamePC>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMainGamePC_Statics::NewProp_DSGameInputContext = { "DSGameInputContext", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainGamePC, DSGameInputContext), Z_Construct_UClass_UInputMappingContext_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DSGameInputContext_MetaData), NewProp_DSGameInputContext_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMainGamePC_Statics::NewProp_MaxPitchAngle = { "MaxPitchAngle", nullptr, (EPropertyFlags)0x0020080000010015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainGamePC, MaxPitchAngle), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxPitchAngle_MetaData), NewProp_MaxPitchAngle_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMainGamePC_Statics::NewProp_MinPitchAngle = { "MinPitchAngle", nullptr, (EPropertyFlags)0x0020080000010015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainGamePC, MinPitchAngle), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MinPitchAngle_MetaData), NewProp_MinPitchAngle_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMainGamePC_Statics::NewProp_LookAction = { "LookAction", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainGamePC, LookAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LookAction_MetaData), NewProp_LookAction_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMainGamePC_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainGamePC_Statics::NewProp_DSGameInputContext,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainGamePC_Statics::NewProp_MaxPitchAngle,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainGamePC_Statics::NewProp_MinPitchAngle,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainGamePC_Statics::NewProp_LookAction,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMainGamePC_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AMainGamePC_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_APlayerController,
	(UObject* (*)())Z_Construct_UPackage__Script_ProjectDS,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMainGamePC_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AMainGamePC_Statics::ClassParams = {
	&AMainGamePC::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AMainGamePC_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AMainGamePC_Statics::PropPointers),
	0,
	0x009002A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AMainGamePC_Statics::Class_MetaDataParams), Z_Construct_UClass_AMainGamePC_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AMainGamePC()
{
	if (!Z_Registration_Info_UClass_AMainGamePC.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AMainGamePC.OuterSingleton, Z_Construct_UClass_AMainGamePC_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AMainGamePC.OuterSingleton;
}
template<> PROJECTDS_API UClass* StaticClass<AMainGamePC>()
{
	return AMainGamePC::StaticClass();
}
AMainGamePC::AMainGamePC(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(AMainGamePC);
AMainGamePC::~AMainGamePC() {}
// End Class AMainGamePC

// Begin Registration
struct Z_CompiledInDeferFile_FID_unreal_ProjectDS_ProjectDS_Source_ProjectDS_Public_Controller_MainGamePC_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AMainGamePC, AMainGamePC::StaticClass, TEXT("AMainGamePC"), &Z_Registration_Info_UClass_AMainGamePC, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AMainGamePC), 3324857191U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_unreal_ProjectDS_ProjectDS_Source_ProjectDS_Public_Controller_MainGamePC_h_598623378(TEXT("/Script/ProjectDS"),
	Z_CompiledInDeferFile_FID_unreal_ProjectDS_ProjectDS_Source_ProjectDS_Public_Controller_MainGamePC_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_unreal_ProjectDS_ProjectDS_Source_ProjectDS_Public_Controller_MainGamePC_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
