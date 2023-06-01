# credit: https://stackoverflow.com/a/65133324/958007

# This copies over our assets to the executable (build) directory.
# That way, our paths are always relative to the executable.
# IRL, we'd have another script that would pull down the assets,
#   b/c we normally don't want assets/binaries to live in Git
#   (there are dedicated version control systems for art).

file(COPY ${CMAKE_CURRENT_LIST_DIR}/assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
