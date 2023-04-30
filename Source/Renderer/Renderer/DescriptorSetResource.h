#pragma once

#include <Renderer/RenderPassResources.h>

#include <Base/Types.h>
#include <Base/Util/StringUtils.h>

namespace Renderer
{
    class DescriptorSet;
    class RenderGraphResources;

    STRONG_TYPEDEF(DescriptorSetID, u16);

    class DescriptorSetResource
    {
    public:
        DescriptorSetResource();
        DescriptorSetResource(DescriptorSetID id, RenderGraphResources& renderGraphResources);

        void Bind(StringUtils::StringHash nameHash, ImageResource resource, u32 mipLevel = 0) const;
        void BindArray(StringUtils::StringHash nameHash, ImageResource resource, u32 mipLevel, u32 arrayIndex) const;

        void Bind(StringUtils::StringHash nameHash, ImageMutableResource resource, u32 mipLevel = 0) const;
        void BindArray(StringUtils::StringHash nameHash, ImageMutableResource resource, u32 mipLevel, u32 arrayIndex) const;

        void Bind(StringUtils::StringHash nameHash, DepthImageResource resource) const;
        void BindArray(StringUtils::StringHash nameHash, DepthImageResource resource, u32 arrayIndex) const;

        void Bind(StringUtils::StringHash nameHash, DepthImageMutableResource resource) const;
        void BindArray(StringUtils::StringHash nameHash, DepthImageMutableResource resource, u32 arrayIndex) const;

        void BindStorage(StringUtils::StringHash nameHash, ImageMutableResource resource, u32 mipLevel = 0, u32 mipCount = 1) const;
        void BindStorageArray(StringUtils::StringHash nameHash, ImageMutableResource resource, u32 mipLevel = 0, u32 mipCount = 1) const;

        DescriptorSetID GetID() { return _id; }

    private:
        DescriptorSetID _id;

        RenderGraphResources* _renderGraphResources;
    };
}