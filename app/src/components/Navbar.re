let navbarStyle =
  Css.(
    style([
      display(`flex),
      justifyContent(`spaceBetween),
      marginBottom(`rem(5.0)),
    ])
  );

let linkListStyle =
  Css.(
    style([
      fontSize(`rem(0.7)),
      selector("ul", [listStyleType(`none), padding(`zero), display(`flex)]),
      selector(
        "li a",
        [
          color(white),
          fontSize(`rem(1.2)),
          fontWeight(`bold),
          marginRight(rem(1.0)),
          fontFamily("Roboto, sans-serif"),
        ],
      ),
    ])
  );
[@react.component]
let make = () => {
  <div className=navbarStyle>
    <div className=linkListStyle>
      "A meetup for everyone where Queer Speakers take the stage"->React.string
      <ul>
        <li>
          <Router.Link href="/"> "Home"->React.string </Router.Link>
        </li>
        <li>
          <Router.Link href="/meetup"> "Demo"->React.string </Router.Link>
        </li>
      </ul>
    </div>
    <img height="55" src="/logo.png" alt="Queer JS" />
  </div>;
};