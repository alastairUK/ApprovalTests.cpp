<a id="top"></a>

# Conan Integration

toc

## Using Conan to obtain ApprovalTests.cpp

See  Daniel Heater's [ApprovalTests-ConanDemo repo](https://github.com/dheater/ApprovalTests-ConanDemo) for an example that demonstrates using ApprovalTests.cpp with the [Conan package manager]([Conan](https://conan.io)).

## Links

* For users: [conan.io/center/approvaltests.cpp](https://conan.io/center/approvaltests.cpp/8.1.0/?user=_&channel=_)
* For maintainers: [the Conan recipe: approvaltests.cpp](https://github.com/conan-io/conan-center-index/tree/master/recipes/approvaltests.cpp)

## How to add a new release to Conan

TODO Automate this!

* Fork the [conan-center-index](https://github.com/conan-io/conan-center-index/) repo.
* Calculate the sha256 sums for the files to add to Conan:
```bash
shasum -a 256 ApprovalTests.v.8.1.1.hpp
shasum -a 256 LICENSE
```
* Add the new block of output to [conandata.yml](https://github.com/conan-io/conan-center-index/blob/master/recipes/approvaltests.cpp/all/conandata.yml) in your fork.
* Test the addition to release Conan:
```bash
cd conan-center-index/recipes/approvaltests.cpp/all
conan create . 8.1.1@
```

* Submit a pull request

---

[Back to User Guide](/doc/README.md#top)