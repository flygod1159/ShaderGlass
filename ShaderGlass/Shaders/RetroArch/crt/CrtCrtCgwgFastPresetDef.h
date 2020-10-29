/*
ShaderGlass preset crt / crt-cgwg-fast imported from RetroArch:
https://github.com/libretro/slang-shaders/blob/master/crt/crt-cgwg-fast.slangp
See original file for credits and usage license. 
This file is auto-generated, do not modify directly.
*/

#pragma once

namespace RetroArch
{
class CrtCrtCgwgFastPresetDef : public PresetDef
{
public:
	CrtCrtCgwgFastPresetDef() : PresetDef{}
	{
		Name = "crt-cgwg-fast";
		Category = "crt";
	}

	virtual void Build() {
         	ShaderDefs.push_back(CrtShadersCrtCgwgFastShaderDef()
.Param("filter_linear", "false"));
	}
};
}
