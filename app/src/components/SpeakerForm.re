open Types.Person;

let containerStyle =
  Css.(
    style([
      backgroundColor(`hex("ffcccc")),
      borderRadius(`px(8)),
      padding(`rem(1.)),
      color(black),
    ])
  );

[@react.component]
let make = (~isOpen, ~onToggle, ~onSubmit) => {
  let (name, setName) = React.useState(() => "");

  let onSubmitCallback = () => {
    let newSpeaker = {name, twitterUserName: None, image: None};

    onToggle(false);
    onSubmit(newSpeaker);
  };

  if (isOpen) {
    <div className=containerStyle>
      <label htmlFor="name"> "Speaker name"->React.string </label>
      <br />
      <input
        type_="text"
        id="name"
        value=name
        onChange={event => {
          let value = ReactEvent.Form.target(event)##value;
          setName(_ => value);
        }}
      />
      <br />
      <button onClick={_ => onSubmitCallback()}>
        "Add Speaker"->React.string
      </button>
      <button onClick={_ => onToggle(false)}> "Close"->React.string </button>
    </div>;
  } else {
    <div>
      <button onClick={_ => onToggle(true)}>
        "Add a speaker"->React.string
      </button>
    </div>;
  };
};