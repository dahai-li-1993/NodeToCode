// Copyright (c) 2025 Nick McClure (Protospatial). All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "N2CLLMPricing.h"
#include "N2CLLMModels.generated.h"



/** Available OpenAI models */
UENUM(BlueprintType)
enum class EN2COpenAIModel : uint8
{
    GPT_5_3_Codex           UMETA(DisplayName = "GPT-5.3 Codex", Value = "gpt-5.3-codex"),
};

/** Available DeepSeek models */
UENUM(BlueprintType)
enum class EN2CDeepSeekModel : uint8
{
    DeepSeek_R1      UMETA(DisplayName = "DeepSeek R1", Value = "deepseek-reasoner"),
    DeepSeek_V3      UMETA(DisplayName = "DeepSeek V3", Value = "deepseek-chat"),
};


/** Helper functions for model enums */
struct FN2CLLMModelUtils
{
    /** Model value getters */
    static FString GetOpenAIModelValue(EN2COpenAIModel Model);
    static FString GetDeepSeekModelValue(EN2CDeepSeekModel Model);

    /** Pricing getters */
    static FN2COpenAIPricing GetOpenAIPricing(EN2COpenAIModel Model);
    static FN2CDeepSeekPricing GetDeepSeekPricing(EN2CDeepSeekModel Model);

    /** System prompt support checks */
    static bool SupportsSystemPrompts(EN2COpenAIModel)
    {
        return true;
    }

private:
    /** Static pricing maps */
    static const TMap<EN2COpenAIModel, FN2COpenAIPricing> OpenAIPricing;
    static const TMap<EN2CDeepSeekModel, FN2CDeepSeekPricing> DeepSeekPricing;
};
