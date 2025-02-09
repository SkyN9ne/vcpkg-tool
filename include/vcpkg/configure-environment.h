#pragma once

#include <vcpkg/base/fwd/downloads.h>
#include <vcpkg/base/fwd/files.h>

#include <vcpkg/fwd/vcpkgpaths.h>

#include <vcpkg/base/expected.h>
#include <vcpkg/base/span.h>
#include <vcpkg/base/stringview.h>
#include <vcpkg/base/util.h>

#include <vcpkg/vcpkgcmdarguments.h>

#include <string>

namespace vcpkg
{
    ExpectedL<Path> download_vcpkg_standalone_bundle(const DownloadManager& download_manager,
                                                     const Filesystem& fs,
                                                     const Path& download_root);

    int run_configure_environment_command(const VcpkgPaths& paths, View<std::string> args);

    constexpr StringLiteral OPTION_VERSION = "version";

    constexpr StringLiteral SWITCH_WINDOWS = "windows";
    constexpr StringLiteral SWITCH_OSX = "osx";
    constexpr StringLiteral SWITCH_LINUX = "linux";
    constexpr StringLiteral SWITCH_FREEBSD = "freebsd";
    constexpr StringLiteral SWITCH_X86 = "x86";
    constexpr StringLiteral SWITCH_X64 = "x64";
    constexpr StringLiteral SWITCH_ARM = "arm";
    constexpr StringLiteral SWITCH_ARM64 = "arm64";
    constexpr StringLiteral SWITCH_TARGET_X86 = "target:x86";
    constexpr StringLiteral SWITCH_TARGET_X64 = "target:x64";
    constexpr StringLiteral SWITCH_TARGET_ARM = "target:arm";
    constexpr StringLiteral SWITCH_TARGET_ARM64 = "target:arm64";
    constexpr StringLiteral SWITCH_FORCE = "force";
    constexpr StringLiteral SWITCH_ALL_LANGUAGES = "all-languages";

    constexpr CommandSwitch CommonAcquireArtifactSwitches[] = {
        {SWITCH_WINDOWS, [] { return msg::format(msgArtifactsSwitchWindows); }},
        {SWITCH_OSX, [] { return msg::format(msgArtifactsSwitchOsx); }},
        {SWITCH_LINUX, [] { return msg::format(msgArtifactsSwitchLinux); }},
        {SWITCH_FREEBSD, [] { return msg::format(msgArtifactsSwitchFreebsd); }},
        {SWITCH_X86, [] { return msg::format(msgArtifactsSwitchX86); }},
        {SWITCH_X64, [] { return msg::format(msgArtifactsSwitchX64); }},
        {SWITCH_ARM, [] { return msg::format(msgArtifactsSwitchARM); }},
        {SWITCH_ARM64, [] { return msg::format(msgArtifactsSwitchARM64); }},
        {SWITCH_TARGET_X86, [] { return msg::format(msgArtifactsSwitchTargetX86); }},
        {SWITCH_TARGET_X64, [] { return msg::format(msgArtifactsSwitchTargetX64); }},
        {SWITCH_TARGET_ARM, [] { return msg::format(msgArtifactsSwitchTargetARM); }},
        {SWITCH_TARGET_ARM64, [] { return msg::format(msgArtifactsSwitchTargetARM64); }},
        {SWITCH_FORCE, [] { return msg::format(msgArtifactsSwitchForce); }},
        {SWITCH_ALL_LANGUAGES, [] { return msg::format(msgArtifactsSwitchAllLanguages); }},
    };

    constexpr CommandSetting CommonSelectArtifactVersionSettings[] = {
        {OPTION_VERSION, [] { return msg::format(msgArtifactsOptionVersion); }},
    };

    // Copies the switches and settings, but not multisettings from parsed to appended_to, and checks that the switches
    // that apply to artifacts meet semantic rules like only one operating system being selected.
    void forward_common_artifacts_arguments(std::vector<std::string>& appended_to, const ParsedArguments& parsed);
}
