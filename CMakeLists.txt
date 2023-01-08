cmake_minimum_required(VERSION 3.16)

project(amp-man VERSION 0.0.1)

add_subdirectory(JUCE)

juce_add_plugin(${PROJECT_NAME}
        FORMATS Standalone VST3 Unity
        )

target_sources(${PROJECT_NAME}
        PRIVATE
        src/pluginProcessor.cpp
        src/pluginAudioEditor.cpp
        )

target_compile_definitions(${PROJECT_NAME}
    PUBLIC
        # JUCE_WEB_BROWSER and JUCE_USE_CURL would be on by default, but you might not need them.
        JUCE_WEB_BROWSER=0  # If you remove this, add `NEEDS_WEB_BROWSER TRUE` to the `juce_add_plugin` call
        JUCE_USE_CURL=0     # If you remove this, add `NEEDS_CURL TRUE` to the `juce_add_plugin` call
        JUCE_VST3_CAN_REPLACE_VST2=0)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        # AudioPluginData           # If we'd created a binary data target, we'd link to it here
        juce::juce_audio_utils
    PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_lto_flags
        juce::juce_recommended_warning_flags)
