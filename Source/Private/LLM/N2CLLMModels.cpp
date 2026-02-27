// Copyright (c) 2025 Nick McClure (Protospatial). All Rights Reserved.

#include "LLM/N2CLLMModels.h"
#include "LLM/N2CLLMPricing.h"

// Initialize static pricing maps
const TMap<EN2COpenAIModel, FN2COpenAIPricing> FN2CLLMModelUtils::OpenAIPricing = {
    {EN2COpenAIModel::GPT_5_3_Codex, FN2COpenAIPricing(0.0f, 0.0f)}
};

const TMap<EN2CDeepSeekModel, FN2CDeepSeekPricing> FN2CLLMModelUtils::DeepSeekPricing = {
    {EN2CDeepSeekModel::DeepSeek_R1, FN2CDeepSeekPricing(0.14f, 0.55f)},
    {EN2CDeepSeekModel::DeepSeek_V3, FN2CDeepSeekPricing(0.07f, 0.27f)}
};

FString FN2CLLMModelUtils::GetOpenAIModelValue(EN2COpenAIModel)
{
    return TEXT("gpt-5.3-codex");
}


FString FN2CLLMModelUtils::GetDeepSeekModelValue(EN2CDeepSeekModel Model)
{
    switch (Model)
    {
        case EN2CDeepSeekModel::DeepSeek_R1:
            return TEXT("deepseek-reasoner");
        case EN2CDeepSeekModel::DeepSeek_V3:
            return TEXT("deepseek-chat");
        default:
            return TEXT("deepseek-reasoner");
    }
}

FN2COpenAIPricing FN2CLLMModelUtils::GetOpenAIPricing(EN2COpenAIModel Model)
{
    if (const FN2COpenAIPricing* Found = OpenAIPricing.Find(Model))
    {
        return *Found;
    }
    return FN2COpenAIPricing();
}

FN2CDeepSeekPricing FN2CLLMModelUtils::GetDeepSeekPricing(EN2CDeepSeekModel Model)
{
    if (const FN2CDeepSeekPricing* Found = DeepSeekPricing.Find(Model))
    {
        return *Found;
    }
    return FN2CDeepSeekPricing();
}
