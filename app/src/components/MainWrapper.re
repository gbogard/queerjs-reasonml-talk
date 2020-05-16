module Stripes = {
  let colors =
    Css.[
      hex("FF5372"),
      hex("FF6B45"),
      hex("FFB93C"),
      hex("7DDA83"),
      hex("02C5F0"),
      hex("A96DCD"),
    ];

  let wrapper =
    Css.(
      style([
        display(`flex),
        flexDirection(`column),
        zIndex(2),
        position(`fixed),
        left(`zero),
        top(`zero),
        bottom(`zero),
        width(`px(100)),
      ])
    );

  let stripe = stripeColor =>
    Css.(style([flexGrow(1.0), backgroundColor(stripeColor)]));

  [@react.component]
  let make = () => {
    <div className=wrapper>
      {colors
       ->Belt.List.map(c => <div className={stripe(c)} />)
       ->Belt.List.toArray
       ->React.array}
    </div>;
  };
};

let backgroundStyle =
  Css.(
    style([
      position(`absolute),
      top(`rem(-1.0)),
      left(`zero),
      right(`zero),
      boxSizing(`borderBox),
      fontSize(`rem(5.0)),
      letterSpacing(`rem(0.75)),
      color(rgb(51, 26, 66)),
      fontWeight(`bold),
      zIndex(1),
      transform(rotate(deg(-3.0))),
      whiteSpace(`nowrap),
      overflow(`hidden)
    ])
  );

let wrapperStyle =
  Css.(
    style([
      position(`relative),
      maxWidth(`px(900)),
      zIndex(2),
      margin4(~top=`rem(4.0), ~bottom=`zero, ~left=`auto, ~right=`auto),
    ])
  );

[@react.component]
let make = (~children) =>
  <>
    <div className=backgroundStyle>
      "~=~>&&<{=$%~%~= >}>[][ ]~=~>&&~"->React.string
      <br/>
      "=~>& &<{==>}  ><{  =$$%  ~ =>  }  >[ ]"->React.string
    </div>
    <Stripes />
    <div className=wrapperStyle> <Navbar /> children </div>
  </>;