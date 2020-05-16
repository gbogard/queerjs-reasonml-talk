open Rationale.Option;
open Rationale.Option.Infix;

/**
 * This URL wrapper add a little bit more type-safety.
 * It prevents us from accidently mixing urls and other strings.
 * URLs will get their own type at compile time, with no runtime cost,
 * because URLs are just strings at runtime.
 * 
 * This is called a polymorphic variant :) 
 */
type url = [ | `url(string)];

module Person = {
  type t = {
    name: string,
    image: option(url),
    twitterUserName: option(string),
  };

  let defaultImg = `url("/doggo.jpg");

  let getImageFromTwitter = username =>
    `url("https://twitter-avatar.now.sh/" ++ username);

  /**
   * Here how this cryptic part works:
   * 
   * person.image is an option(url) (either a Some(url) or a None)
   * person.twitterUserName is an option(string) (either a Some(string) or a None)
   * 
   * person.twitterUserName |> map(getImageFromTwitter)
   * applies the getImageFromTwitter function to the person.twitterUserName option
   * If the option is a Some (i.e., the user has a username), it will return a
   * Some of `person.twitterUserName(image)`.
   * 
   * If the option is a None, the function won't be applied, and the return will also be a None.
   * Essentially, mapping is applying a function to the content of structure, while preserving
   * the shape of the structure.
   * 
   * Writing "a |? b", where a and b are both Options, means "a or b". It will return the first
   * Some it finds (left-to-right), returning a None if both Options are Nones
   * 
   * Writing "a |> default(defaultValue)" is like writing "default(defaultValue, a)"
   * It means "return the value of a if it's a Some, else return the default value"
   * 
   * The final expression means
   *  - does the person has an image, if so return it
   *  - if not does they have a twitter handle, if so transform it to a url using a function,
   * then return it
   * - if not return a default url
   * 
   * So it's essentially optional-chaning and null-coalescing of latest Ecmascript, 
   * in a truely type-safe way, in a 30 year-old language <3
   */
  let getImage = person =>
    person.image
    |? (person.twitterUserName |> map(getImageFromTwitter))
    |> default(defaultImg);
};