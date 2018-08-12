// Float Remap Material Expression - Anand Hotwani (2018)
//
// Based on Utility Function written by Anders Langlands: https://bitbucket.org/anderslanglands/alshaders/src
//
//
#pragma once
#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "MaterialExpressionIO.h"
#include "Materials/MaterialExpression.h"
#include "ahMaterialExpressionFloatRemap.generated.h"

UCLASS(collapsecategories, hidecategories = Object)
class UMaterialExpressionAhFloatRemap : public UMaterialExpression
{
	GENERATED_UCLASS_BODY()

		UPROPERTY()
		FExpressionInput Input;

	UPROPERTY()
		FExpressionInput Mask;

	// INPUT CLAMPING
	UPROPERTY(EditAnywhere, Category = Remap, meta = (ToolTip = "Sets the minimum input value. Use this to pull values outside of 0-1 into a 0-1 range."))
		float Input_Min;
	UPROPERTY(EditAnywhere, Category = Remap, meta = (ToolTip = "Sets the maximum input value. Use this to pull values outside of 0-1 into a 0-1 range."))
		float Input_Max;


	// CONTRAST
	UPROPERTY(EditAnywhere, Category = Contrast, meta = (ToolTip = "Scales the contrast of the input signal."))
		float Contrast;
	UPROPERTY(EditAnywhere, Category = Contrast, meta = (ToolTip = "Sets the pivot point around which the input signal is contrasted."))
		float Pivot;

	// BIAS AND GAIN
	UPROPERTY(EditAnywhere, Category = Bias_and_Gain, meta = (ToolTip = "Bias the signal higher or lower. Values less than 0.5 push the average lower, values higher than 0.5 push it higher."))
		float Bias;
	UPROPERTY(EditAnywhere, Category = Bias_and_Gain, meta = (ToolTip = "Adds gain to the signal, in effect a different form of contrast. Values less than 0.5 increase the gain, values greater than 0.5 decrease it."))
		float Gain;
	UPROPERTY(EditAnywhere, Category = Bias_and_Gain, meta = (ToolTip = "Sets the minimum value of the output. Use this to scale a 0-1 signal to a new range."))
		float Output_Min;
	UPROPERTY(EditAnywhere, Category = Bias_and_Gain, meta = (ToolTip = "Sets the maximum value of the output. Use this to scale a 0-1 signal to a new range."))
		float Output_Max;

	// CLAMP OUTPUT
	UPROPERTY(EditAnywhere, Category = Clamp, meta = (ToolTip = "When enabled, will clamp the output to Min-Max."))
		bool Clamp;
	UPROPERTY(EditAnywhere, Category = Clamp, meta = (ToolTip = "When enabled, will expand the clamped range to 0-1 after clamping."))
		bool Expand;
	UPROPERTY(EditAnywhere, Category = Clamp, meta = (ToolTip = "Minimum value to clamp to."))
		float Min;
	UPROPERTY(EditAnywhere, Category = Clamp, meta = (ToolTip = "Maximum value to clamp to."))
		float Max;

	//~ Begin UMaterialExpression Interface
#if WITH_EDITOR
	virtual int32 Compile(class FMaterialCompiler* Compiler, int32 OutputIndex) override;
	virtual void GetCaption(TArray<FString>& OutCaptions) const override;
	virtual bool NeedsRealtimePreview() override { return true; }
#endif
	//~ End UMaterialExpression Interface

};

