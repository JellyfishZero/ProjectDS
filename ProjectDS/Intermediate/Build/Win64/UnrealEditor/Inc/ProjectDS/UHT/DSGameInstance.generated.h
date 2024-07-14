// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "DSGameInstance.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef PROJECTDS_DSGameInstance_generated_h
#error "DSGameInstance.generated.h already included, missing '#pragma once' in DSGameInstance.h"
#endif
#define PROJECTDS_DSGameInstance_generated_h

#define FID_unreal_ProjectDS_ProjectDS_Source_ProjectDS_Public_DSGameInstance_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUDSGameInstance(); \
	friend struct Z_Construct_UClass_UDSGameInstance_Statics; \
public: \
	DECLARE_CLASS(UDSGameInstance, UGameInstance, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/ProjectDS"), NO_API) \
	DECLARE_SERIALIZER(UDSGameInstance)


#define FID_unreal_ProjectDS_ProjectDS_Source_ProjectDS_Public_DSGameInstance_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UDSGameInstance(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UDSGameInstance(UDSGameInstance&&); \
	UDSGameInstance(const UDSGameInstance&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDSGameInstance); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDSGameInstance); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UDSGameInstance) \
	NO_API virtual ~UDSGameInstance();


#define FID_unreal_ProjectDS_ProjectDS_Source_ProjectDS_Public_DSGameInstance_h_12_PROLOG
#define FID_unreal_ProjectDS_ProjectDS_Source_ProjectDS_Public_DSGameInstance_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_unreal_ProjectDS_ProjectDS_Source_ProjectDS_Public_DSGameInstance_h_15_INCLASS_NO_PURE_DECLS \
	FID_unreal_ProjectDS_ProjectDS_Source_ProjectDS_Public_DSGameInstance_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PROJECTDS_API UClass* StaticClass<class UDSGameInstance>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_unreal_ProjectDS_ProjectDS_Source_ProjectDS_Public_DSGameInstance_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
