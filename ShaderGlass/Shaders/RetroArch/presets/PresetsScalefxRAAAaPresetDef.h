/*
ShaderGlass preset presets / scalefx+rAA+aa imported from RetroArch:
https://github.com/libretro/slang-shaders/blob/master/presets/scalefx+rAA+aa.slangp
See original file for credits and usage license. 
This file is auto-generated, do not modify directly.
*/

#pragma once

namespace RetroArch
{
class PresetsScalefxRAAAaPresetDef : public PresetDef
{
public:
	PresetsScalefxRAAAaPresetDef() : PresetDef{}
	{
		Name = "scalefx+rAA+aa";
		Category = "presets";
	}

	virtual void Build() {
         	ShaderDefs.push_back(StockStockShaderDef()
.Param("alias", "refpass")
.Param("filter_linear", "false"));
         	ShaderDefs.push_back(ScalefxShadersScalefxPass0ShaderDef()
.Param("alias", "scalefx_pass0")
.Param("filter_linear", "false")
.Param("float_framebuffer", "true")
.Param("scale", "1.0")
.Param("scale_type", "source"));
         	ShaderDefs.push_back(ScalefxShadersScalefxPass1ShaderDef()
.Param("filter_linear", "false")
.Param("float_framebuffer", "true")
.Param("scale", "1.0")
.Param("scale_type", "source"));
         	ShaderDefs.push_back(ScalefxShadersScalefxPass2ShaderDef()
.Param("filter_linear", "false")
.Param("scale", "1.0")
.Param("scale_type", "source"));
         	ShaderDefs.push_back(ScalefxShadersScalefxPass3ShaderDef()
.Param("filter_linear", "false")
.Param("scale", "1.0")
.Param("scale_type", "source"));
         	ShaderDefs.push_back(ScalefxShadersScalefxPass4ShaderDef()
.Param("filter_linear", "false")
.Param("scale", "3.0")
.Param("scale_type", "source"));
         	ShaderDefs.push_back(AntiAliasingShadersReverseAaPost3xReverseAaPost3xPass0ShaderDef()
.Param("filter_linear", "false")
.Param("scale", "1.0")
.Param("scale_type", "source"));
         	ShaderDefs.push_back(AntiAliasingShadersReverseAaPost3xReverseAaPost3xPass1ShaderDef()
.Param("filter_linear", "false")
.Param("scale", "1.0")
.Param("scale_type", "source"));
         	ShaderDefs.push_back(AntiAliasingShadersFxaaShaderDef()
.Param("filter_linear", "true")
.Param("scale", "1.0")
.Param("scale_type", "source"));
         	ShaderDefs.push_back(XsoftShaders4xsoftShaderDef()
.Param("filter_linear", "true")
.Param("scale", "2.0")
.Param("scale_type", "source"));
         	ShaderDefs.push_back(SharpenShadersFastSharpenShaderDef()
.Param("filter_linear", "true")
.Param("scale", "1.0")
.Param("scale_type", "source"));
         	ShaderDefs.push_back(DeblurShadersDeblurShaderDef()
.Param("filter_linear", "true")
.Param("scale", "1.0")
.Param("scale_type", "viewport"));
	}
};
}
