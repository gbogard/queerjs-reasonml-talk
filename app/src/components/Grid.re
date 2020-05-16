let gridStyle = nbOfColumns =>
  Css.(
    style([
      display(`grid),
      gridTemplateColumns([`repeat((`num(nbOfColumns), `fr(1.0)))]),
    ])
  );

[@react.component]
let make = (~nbOfColumns, ~children) => {
  <div className={gridStyle(nbOfColumns)}> children </div>;
};