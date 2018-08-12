// Color Remap Material Expression - Anand Hotwani (2018)
//
// Based on Utility Function written by Anders Langlands: https://bitbucket.org/anderslanglands/alshaders/src
//
//
#pragma once
#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "MaterialExpressionIO.h"
#include "Materials/MaterialExpression.h"
#include "ahMaterialExpressionColorRemap.generated.h"

UCLASS(collapsecategories, hidecategories = Object)
class UMaterialExpressionAhColorRemap : public UMaterialExpression
{
	GENERATED_UCLASS_BODY()

		UPROPERTY()
		FExpressionInput Input;

	UPROPERTY()
		FExpressionInput Mask;

	// INPUT 
	UPROPERTY(EditAnywhere, Category = Remap, meta = (ToolTip = "Gamma value to apply to input."))
		float Gamma;
	UPROPERTY(EditAnywhere, Category = Remap, meta = (ToolTip = "Saturation to apply to the input."))
		float Saturation;
	UPROPERTY(EditAnywhere, Category = Remap, meta = (ToolTip = "Hue offset to apply to the input."))
		float HueOffset;

	// CONTRAST
	UPROPERTY(EditAnywhere, Category = Contrast, meta = (ToolTip = "Scales the contrast of the input signal."))
		float Contrast;
	UPROPERTY(EditAnywhere, Category = Contrast, meta = (ToolTip = "Sets the pivot point around which the input signal is contrasted."))
		float Pivot;
	UPROPERTY(EditAnywhere, Category = Contrast, meta = (ToolTip = "Adds gain to the signal, in effect a different form of contrast. Values less than 0.5 increase the gain, values greater than 0.5 decrease it."))
		float Gain;
	UPROPERTY(EditAnywhere, Category = Contrast, meta = (ToolTip = "Exposure adjustment to apply to the input, i.e. input * 2^exposure."))
		float Exposure;


	//~ Begin UMaterialExpression Interface
#if WITH_EDITOR
	virtual int32 Compile(class FMaterialCompiler* Compiler, int32 OutputIndex) override;
	virtual void GetCaption(TArray<FString>& OutCaptions) const override;
	virtual bool NeedsRealtimePreview() override { return true; }
#endif
	//~ End UMaterialExpression Interface

};

