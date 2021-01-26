#pragma once
#include <cstdint>
#include <nlohmann/json.hpp>
#include <vector>

#include "DatatypeEnum.hpp"
#include "RawBuffer.hpp"

namespace dai {

struct RawCameraControl : public RawBuffer {
    enum class AutoFocusMode : uint8_t {
        OFF = 0,
        AUTO,
        MACRO,
        CONTINUOUS_VIDEO,
        CONTINUOUS_PICTURE,
        EDOF,
    };

    AutoFocusMode autoFocusMode = AutoFocusMode::CONTINUOUS_VIDEO;

    // TODO(themarpe/alex) - this is a placeholder for vairous camera control commands
    bool captureStill = false;

    void serialize(std::vector<std::uint8_t>& metadata, DatatypeEnum& datatype) override {
        nlohmann::json j = *this;
        metadata = nlohmann::json::to_msgpack(j);
        datatype = DatatypeEnum::CameraControl;
    };

    NLOHMANN_DEFINE_TYPE_INTRUSIVE(RawCameraControl, captureStill, autoFocusMode);
};

}  // namespace dai