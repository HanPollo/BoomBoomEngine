//
// Created by pollo on 4/28/2022.
//
#pragma once

#include "shape.h"

namespace BoomBoom
{

    Shape join(const Shape& rhs, const Shape& lhs)
    {
        Shape shape(rhs);

        Index offset = shape.indices.size();

        // TODO: resize before pushing new elements

        for (auto const& vertex : lhs.vertices)
            shape.vertices.push_back(vertex);

        for (auto const& index : lhs.indices)
            shape.indices.push_back(offset + index);

        return shape;
    }

    namespace
    {
        template <typename ValueT>
        std::ostream& to_ostream(std::ostream& os, const std::vector<ValueT>& values)
        {
            os << "[";

            auto valueIt = values.begin();
            while (valueIt != values.end())
            {
                auto& value = *valueIt;
                os << value;
                valueIt++;

                if (valueIt != values.end())
                    os << ", ";
            }

            os << "]";

            return os;
        }
    }

    std::ostream& operator<<(std::ostream& os, const Vertices& vertices)
    {
        return to_ostream(os, vertices);
    }

    std::ostream& operator<<(std::ostream& os, const Indices& indices)
    {
        return to_ostream(os, indices);
    }

    std::ostream& operator<<(std::ostream& os, const Shape& shape)
    {
        os << "{ vertices: " << shape.vertices
           << ", indices: " << shape.indices << "}";

        return os;
    }

}