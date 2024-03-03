workspace "MedievalIdle"
	architecture "x64"
	
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["SFML"] = "MedievalIdle/vendor/SFML/include"
IncludeDir["ImGui"] = "MedievalIdle/vendor/imgui"
IncludeDir["ImGuiSFML"] = "MedievalIdle/vendor/imgui-sfml"
IncludeDir["glm"] = "MedievalIdle/vendor/glm"

include "MedievalIdle/vendor/imgui"
include "MedievalIdle/vendor/imgui-sfml"

project "MedievalIdle"
	location "MedievalIdle"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "MedievalIdlePCH.h"
	pchsource "MedievalIdle/src/MedievalIdlePCH.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/*.hpp",
		"%{prj.name}/vendor/glm/glm/*.inl"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.SFML}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.ImGuiSFML}",
		"%{IncludeDir.glm}"
	}

	libdirs 
	{ 
		"%{prj.name}/vendor/SFML/lib",
		"%{prj.name}/vendor/imgui/bin/",
		"%{prj.name}/vendor/imgui-sfml/bin/"
	}

	links
	{
		"ImGui",
		"ImGui-SFML"
	}

	syslibdirs
	{
		"%{prj.name}/vendor/SFML/lib" 
	}


	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"MEDIEVAL_IDLE_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		runtime "Debug"
		defines "MEDIEVAL_IDLE_DEBUG"
		symbols "On"
		links
		{
			"sfml-system-d.lib",	
			"sfml-window-d.lib",
			"sfml-graphics-d.lib",
			"sfml-audio-d.lib",
			"sfml-network-d.lib"
		}

	filter "configurations:Release"
		runtime "Release"
		defines "MEDIEVAL_IDLE_RELEASE"
		optimize "On"
		links
		{
			"sfml-system.lib",
			"sfml-window.lib",
			"sfml-graphics.lib",
			"sfml-audio.lib",
			"sfml-network.lib"
		}

	filter "configurations:Dist"
		runtime "Release"
		defines "MEDIEVAL_IDLE_DIST"
		optimize "On"
		links
		{
			"sfml-system.lib",
			"sfml-window.lib",
			"sfml-graphics.lib",
			"sfml-audio.lib",
			"sfml-network.lib",
		}