open Types.Person;

module Size {
  type t = | Small | Big;

  let toPx = size => switch(size) {
    | Small => Css.px(100)
    | Big => Css.px(240)
  };
}

let imgStyle = (image, imageSize) => Css.(style([
  height(imageSize->Size.toPx),
  width(imageSize->Size.toPx),
  borderRadius(imageSize->Size.toPx),
  backgroundSize(`cover),
  backgroundPosition(`center),
  backgroundImage(`url(image)),
]));

let containerStyle = Css.(style([
  display(`flex),
  flexDirection(`column),
  alignItems(`center),
  selector("span", [
    margin2(~h=`zero, ~v=`rem(1.5)),
    color(white),
    fontSize(`rem(0.9))
  ])
]));


[@react.component]
let make = (~person, ~size) => {
  let `url(img) = person->getImage;

  <div className={containerStyle}>
    <div className={imgStyle(img, size)}></div> 
    <span>{person.name->React.string}</span>
  </div>
}