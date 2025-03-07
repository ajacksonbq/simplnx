# Convert AttributeArray DataType

## Group (Subgroup)

Core (Misc)

## Description

This **Filter** converts attribute data from one primitive type to another by using the built in translation of the compiler. This **Filter** can be used if the user needs to convert an array into a type that is accepted by another **Filter**. For example, a **Filter** may need an input array to be of type _int32_t_ but the array that the user would like to use is _uint16_t_. The user may use this **Filter** to create a new array that has the proper target type (_int32_t_).

**This Filter is here for convenience and should be used with great care and understanding of the input and output data. This Filter should rarely be required, and if the user thinks that they require this Filter then a detailed examination of all the data involved should be undertaken to avoid possible undefined behaviors.**

### Important Notes

**Up Casting**

Upcasting is most likely well defined by the compilers. This is the act of creating a new array using a primitive value that is represented by more bytes than the original data. For example, if the user converts 1 byte integers into 4 byte integers or converted 4 byte floats into 8 byte floats.

**Down Casting**

Down casting can have undefined behavior depending on the primitive types involved. Down casting is the opposite of up casting and involves converting data from a larger byte count representation to a representation of lower byte count. For example, converting 4 byte integers into 2 byte integers or 8 byte floats into 4 byte floats. What happens to the data depends on the range of values in the original array. If the target type's range can hold all the values of the original array's values, then the conversion would have a well defined outcome.

**Signed/Unsigned Conversions**

When converting data from signed values to unsigned values or vice-versa, there can also be undefined behavior. For example, if the user were to convert a signed 4 byte integer array to an unsigned 4 byte integer array and the input array has negative values, then the conversion rules are undefined and may differ from operating system to operating system.

% Auto generated parameter table will be inserted here

## Example Pipelines

## License & Copyright

Please see the description file distributed with this **Plugin**

## DREAM3D-NX Help

If you need help, need to file a bug report or want to request a new feature, please head over to the [DREAM3DNX-Issues](https://github.com/BlueQuartzSoftware/DREAM3DNX-Issues) GItHub site where the community of DREAM3D-NX users can help answer your questions.
